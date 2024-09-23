<?php

/**
 * @file
 * Implements HTTP request header context plugin.
 */

/**
 * Plugins are described by creating a $plugin array which will be used
 * by the system that includes this file.
 */
$plugin = array(
  'title' => t('HTTP Request Header'),
  'description' => t('HTTP Request Header values as CTools context'),
  'context' => 'ctools_header_plugins_request_header_context_create',
  'keyword' => 'request_header',
  'context name' => 'request_header',
  'convert list' => 'ctools_header_plugins_request_header_context_convert_list',
  'convert' => 'ctools_header_plugins_request_header_context_convert',
);

/**
 * It's important to remember that $conf is optional here, because contexts
 * are not always created from the UI.
 */
function ctools_header_plugins_request_header_context_create($empty, $data = NULL, $conf = FALSE) {
  $context = new ctools_context('request_header');
  $context->plugin = 'request_header';

  if ($empty) {
    return $context;
  }

  $data = new stdClass();
  if (isset($_SERVER['HTTP_REFERER'])) {
    $data->referrer = check_plain($_SERVER['HTTP_REFERER']);
  }
  if (isset($_SERVER['HTTP_USER_AGENT'])) {
    $data->user_agent = check_plain($_SERVER['HTTP_USER_AGENT']);
  }
  if (isset($_SERVER['SERVER_NAME'])) {
    $data->host = check_plain($_SERVER['SERVER_NAME']);
  }
  if (isset($_SERVER['HTTP_ACCEPT'])) {
    $data->accept = check_plain($_SERVER['HTTP_ACCEPT']);
  }
  if (isset($_SERVER['HTTP_ACCEPT_ENCODING'])) {
    $data->accept_encoding = check_plain($_SERVER['HTTP_ACCEPT_ENCODING']);
  }
  if (isset($_SERVER['HTTP_ACCEPT_LANGUAGE'])) {
    $data->accept_language = check_plain($_SERVER['HTTP_ACCEPT_LANGUAGE']);
  }
  if (isset($_SERVER['HTTP_CONNECTION'])) {
    $data->connection = check_plain($_SERVER['HTTP_CONNECTION']);
  }
  if (isset($_SERVER['HTTP_ACCEPT_CHARSET'])) {
    $data->accept_charset = check_plain($_SERVER['HTTP_ACCEPT_CHARSET']);
  }

  if (!empty($data)) {
    $context->data = $data;
    $context->title = t('HTTP Request Header');
    return $context;
  }
}

/**
 * Provide a list of ways that this context can be converted to a string.
 */
function ctools_header_plugins_request_header_context_convert_list() {
  return array(
    'referrer' => t('Referrer'),
    'user_agent' => t('User-Agent'),
    'host' => t('Host'),
    'accept' => t('Accept'),
    'accept_charset' => t('Accept-Charset'),
    'accept_encoding' => t('Accept-Encoding'),
    'accept_language' => t('Accept-Language'),
    'connection' => t('Connection'),
  );
}

/**
 * Convert a context into a string.
 */
function ctools_header_plugins_request_header_context_convert($context, $type) {
  return isset($context->data->{$type}) ? $context->data->{$type} : '';
}
