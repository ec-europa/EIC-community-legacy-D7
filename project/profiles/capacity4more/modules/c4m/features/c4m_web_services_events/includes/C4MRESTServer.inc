<?php

/**
 * @file
 * Class for handling REST calls.
 */

class C4MRESTServer extends RESTServer
{
  /* @var $negotiator ServicesContentTypeNegotiatorInterface */
  protected $negotiator;
  /* @var $context ServicesContextInterface */
  protected $context;

  protected $resources;
  protected $parsers;
  protected $formatters;

  protected $controller;

  /**
   * Constructor. Initialize properties.
   */
  function __construct(ServicesContextInterface $context, ServicesContentTypeNegotiatorInterface $negotiator, $resources, $parsers, $formatters)
  {
    parent::__construct($context, $negotiator, $resources, $parsers, $formatters);
  }

  /**
   * Determine controller.
   *
   * @param array $resource
   *   Full definition of the resource.
   * @param string $operation
   *   Type of operation ('index', 'retrieve' etc.). We are going to override this variable.
   *   Needed for applying version.
   *
   * @return array
   *   Controller definition.
   */
  protected function resolveController($resource, &$operation)
  {
    $request_method = $this->getRequestMethod();

    $canonical_path_array = $this->getCanonicalPathArray();
    array_shift($canonical_path_array);

    $canon_path_count = count($canonical_path_array);
    $operation_type = NULL;
    $operation = NULL;

    // For any HEAD request return response "200 OK".
    if ($request_method == 'HEAD') {
      return services_error('OK', 200);
    }

    // For any OPTIONS request return only the headers.
    if ($request_method == 'OPTIONS') {
      exit;
    }

    if ($resource['key'] == 'eventsite') {
      return $this->eventController($resource, $operation, $request_method, $operation_type, $canon_path_count, $canonical_path_array);
    }
    else {
      return $this->defaultController($resource, $operation, $request_method, $operation_type, $canon_path_count, $canonical_path_array);
    }
  }

  /**
   * Determine controller.
   *
   * @param array $resource
   *   Full definition of the resource.
   * @param string $operation
   *   The Type of operation ('index', 'retrieve' etc.). We are going to override this var.
   *   Needed for applying version.
   * @param string $request_method
   *   The Type of http method.
   * @param string $operation_type
   *   The operation type.
   * @param string $canon_path_count
   *   How many items are inside canonical path.
   * @param array $canonical_path_array
   *   The canonical path.
   *
   * @return array
   *   Controller definition.
   */
  protected function defaultController(array $resource, $operation, $request_method, $operation_type, $canon_path_count, array $canonical_path_array) {
    // We do not group "if" conditions on purpose for better readability.
    // 'index' method.
    if ($request_method == 'GET'
      && isset($resource['operations']['index'])
      && $this->checkNumberOfArguments($canon_path_count, $resource['operations']['index'])
    ) {
      $operation_type = 'operations';
      $operation = 'index';
    }

    // We do not group "if" conditions on purpose for better readability.
    // 'index' method.
    // 'retrieve' method.
    // First path element should be not empty.
    if ($request_method == 'GET'
      && $canon_path_count >= 1
      && isset($resource['operations']['retrieve'])
      && $this->checkNumberOfArguments($canon_path_count, $resource['operations']['retrieve'])
      && !empty($canonical_path_array[0])
    ) {
      $operation_type = 'operations';
      $operation = 'retrieve';
    }

    // 'relationships'
    // First path element should be not empty,
    // second should be name of targeted action.
    if ($request_method == 'GET'
      && $canon_path_count >= 2
      && isset($resource['relationships'][$canonical_path_array[1]])
      && $this->checkNumberOfArguments($canon_path_count, $resource['relationships'][$canonical_path_array[1]], 1)
      && isset($canonical_path_array[0])
    ) {
      $operation_type = 'relationships';
      $operation = $canonical_path_array[1];
    }

    // 'update'
    // First path element should be not empty.
    if ($request_method == 'PUT'
      && $canon_path_count >= 1
      && isset($resource['operations']['update'])
      && $this->checkNumberOfArguments($canon_path_count, $resource['operations']['update'])
      && !empty($canonical_path_array[0])
    ) {
      $operation_type = 'operations';
      $operation = 'update';
    }

    // 'custom update'
    // First path element should be not empty.
    if ($request_method == 'PUT'
      && $canon_path_count >= 1
      && isset($resource['operations']['c4m_update_eventsite'])
      && $this->checkNumberOfArguments($canon_path_count, $resource['operations']['c4m_update'])
      && !empty($canonical_path_array[0])
    ) {
      $operation_type = 'operations';
      $operation = 'c4m_update_eventsite';
    }

    // 'delete'
    // First path element should be not empty.
    if ($request_method == 'DELETE'
      && $canon_path_count >= 1
      && isset($resource['operations']['delete'])
      && $this->checkNumberOfArguments($canon_path_count, $resource['operations']['delete'])
      && !empty($canonical_path_array[0])
    ) {
      $operation_type = 'operations';
      $operation = 'delete';
    }

    // 'create' method.
    // First path element should be not empty.
    if ($request_method == 'POST'
      && isset($resource['operations']['create'])
      && $this->checkNumberOfArguments($canon_path_count, $resource['operations']['create'])
    ) {
      $operation_type = 'operations';
      $operation = 'create';
    }

    // 'actions'
    // First path element should be action name
    if ($request_method == 'POST'
      && $canon_path_count >= 1
      && isset($resource['actions'][$canonical_path_array[0]])
      && $this->checkNumberOfArguments($canon_path_count, $resource['actions'][$canonical_path_array[0]], 1)
    ) {
      $operation_type = 'actions';
      $operation = $canonical_path_array[0];
    }

    // 'targeted_actions'
    // First path element should be not empty,
    // second should be name of targeted action.
    if ($request_method == 'POST'
      && $canon_path_count >= 2
      && isset($resource['targeted_actions'][$canonical_path_array[1]])
      && $this->checkNumberOfArguments($canon_path_count, $resource['targeted_actions'][$canonical_path_array[1]], 1)
      && !empty($canonical_path_array[0])
    ) {
      $operation_type = 'targeted_actions';
      $operation = $canonical_path_array[1];
    }

    if (empty($operation_type) || empty($operation) || empty($resource[$operation_type][$operation])) {
      return FALSE;
    }

    $controller = $resource[$operation_type][$operation];

    if (isset($resource['endpoint']['operations'][$operation]['settings'])) {
      // Add the endpoint's settings for the specified operation.
      $controller['endpoint'] = $resource['endpoint']['operations'][$operation]['settings'];
    }

    if (isset($resource['file']) && empty($controller['file'])) {
      $controller['file'] = $resource['file'];
    }

    return $controller;
  }

  /**
   * Determine controller.
   *
   * @param array $resource
   *   Full definition of the resource.
   * @param string $operation
   *   The Type of operation ('index', 'retrieve' etc.). We are going to override this var.
   *   Needed for applying version.
   * @param string $request_method
   *   The Type of http method.
   * @param string $operation_type
   *   The operation type.
   * @param string $canon_path_count
   *   How many items are inside canonical path.
   * @param array $canonical_path_array
   *   The canonical path.
   *
   * @return array
   *   Controller definition.
   */
  protected function eventController(array $resource, $operation, $request_method, $operation_type, $canon_path_count, array $canonical_path_array) {
    /* We do not group "if" conditions on purpose for better readability. */

    // Get all events.
    if ($request_method == 'GET'
    && isset($resource['operations']['index'])
    && $this->checkNumberOfArguments($canon_path_count, $resource['operations']['index'])
    ) {
      $operation_type = 'operations';
      $operation = 'index';
    }
    // get one Event
    if ($request_method == 'GET'
      && $canon_path_count >= 1
      && isset($resource['operations']['retrieve'])
      && $this->checkNumberOfArguments($canon_path_count, $resource['operations']['retrieve'])
      && !empty($canonical_path_array[0])
    ) {
      $operation_type = 'operations';
      $operation = 'retrieve';
    }

    // 'update an event'
    // First path element should be not empty.
    if ($request_method == 'PUT'
      && $canon_path_count >= 1
      && isset($resource['operations']['update'])
      && $this->checkNumberOfArguments($canon_path_count, $resource['operations']['update'])
      && !empty($canonical_path_array[0])
    ) {
      $operation_type = 'operations';
      $operation = 'update';
    }


    // maybe refactor and move outside the metheod
    if (empty($operation_type) || empty($operation) || empty($resource[$operation_type][$operation])) {
      return FALSE;
    }

    $controller = $resource[$operation_type][$operation];

    if (isset($resource['endpoint']['operations'][$operation]['settings'])) {
      // Add the endpoint's settings for the specified operation.
      $controller['endpoint'] = $resource['endpoint']['operations'][$operation]['settings'];
    }

    if (isset($resource['file']) && empty($controller['file'])) {
      $controller['file'] = $resource['file'];
    }

    return $controller;
  }
}