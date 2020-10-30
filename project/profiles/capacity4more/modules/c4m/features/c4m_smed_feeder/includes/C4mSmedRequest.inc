<?php

/**
 * @file
 * Class for handling SMED requests.
 */

class C4mSmedRequest {
  /**
   * The authorization token key.
   *
   * @var string
   */

  protected $endpoint_url;
  /**
   * The authorization token key.
   *
   * @var string
   */
  protected $auth_token;

  /**
   * The basic authentication user.
   *
   * @var string
   */
  protected $basic_auth_user;

  /**
   * The basic authentication password.
   *
   * @var string
   */
  protected $basic_auth_password;

  /**
   * The request payload as an XML structure.
   *
   * @var string
   */
  protected $request_payload;

  /**
   * The request HTTP method.
   *
   * @var string
   */
  protected $request_method;

  /**
   * The request timeout.
   *
   * @var string
   */
  protected $request_timeout;


  /**
   * Constructor. Initialize properties.
   */
  function __construct($endpoint_url = NULL, $auth_token = NULL, $basic_auth_user = NULL, $basic_auth_password = NULL, $request_method = NULL, $request_timeout = NULL) {
    // Get the SMED feeder site configuration details.
    $smed_feeder = variable_get('smed_feeder', []);

    $this->endpoint_url = !is_null($endpoint_url) ? $endpoint_url : $smed_feeder['smed_feeder_endpoint_url'];
    $this->auth_token = !is_null($auth_token) ? $auth_token : $smed_feeder['smed_feeder_authorization_token_key'];
    $this->basic_auth_user = !is_null($basic_auth_user) ? $basic_auth_user : $smed_feeder['smed_feeder_basic_authentication_user'];
    $this->basic_auth_password = !is_null($basic_auth_password) ? $basic_auth_password : $smed_feeder['smed_feeder_basic_authentication_password'];
    $this->request_method = !is_null($request_method) ? $request_method : 'POST';
    $this->request_timeout = !is_null($request_timeout) ? $request_timeout : $smed_feeder['smed_feeder_timeout'];
  }

  /**
   * Adds the payload to the request.
   *
   * @param array $payload
   *   Values to be added to the payload.
   */
  public function requestPayload($payload) {
    // First add the authorization token key to the payload.
    $payload['AuthorizationToken'] = $this->auth_token;

    $this->request_payload = $this->arrayToXml($payload);
  }

  /**
   * Performs the request and returns the result.
   * 
   * @return array
   *   An array with following keys:
   *   - response
   *   - data
   */
  public function sendRequest() {
    $options = [
      'headers' => [
        'Content-Type' => 'application/xml',
        'Authorization' => 'Basic ' . base64_encode($this->basic_auth_user . ':' . $this->basic_auth_password),
      ],
      'method' => $this->request_method,
      'data' => $this->request_payload,
      'timeout' => $this->request_timeout,
    ];

    $url = 'https://' . $this->endpoint_url;
    $response = drupal_http_request($url, $options);
    $xml = simplexml_load_string($response->data, 'SimpleXMLElement', LIBXML_NOCDATA | LIBXML_NOBLANKS);

    $result['response'] = $response;
    $result['data'] = json_decode(json_encode((array) $xml),true);
    return $result;
  }

  /**
   * Turns an array into an XML structure.
   *
   * @param $array
   * @param null $rootElement
   * @param null $xml
   * @return array
   */
  public function arrayToXml($array, $rootElement = null, $xml = null) {
    $_xml = $xml;

    // If there is no Root Element then insert root
    if ($_xml === null) {
      $_xml = new SimpleXMLElement($rootElement !== null ? $rootElement : '<root/>');
    }

    // Visit all key value pair
    foreach ($array as $k => $v) {
      // If there is nested array then
      if (is_array($v)) {
        // Call function for nested array
        arrayToXml($v, $k, $_xml->addChild($k));
      }
      else {
        // Simply add child element.
        $_xml->addChild($k, $v);
      }
    }

    return $_xml->asXML();
  }

}
