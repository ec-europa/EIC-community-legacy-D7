<?php

/**
 * Factory class to build C4MRESTServer object.
 *
 */

class C4MServicesRESTServerFactory extends ServicesRESTServerFactory
{
  protected $data = array();
  static $class_name = 'C4MRESTServer';

  /**
   * We need data property to pass additional arguments to methods.
   *
   * Required property is 'endpoint_path' -- base path of endpoint.
   * Example: GET rest/node/1.php -- "rest" is endpoint path.
   */
  public function __construct($data = array())
  {
    parent::__construct($data);
  }
}