<?php

/**
 * Helper to implementation of hook_context_default_contexts().
 */
function _atrium_intranet_context_default_contexts() {
  $export = array();
  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'atrium-intranet-global';
  $context->description = '';
  $context->tag = 'Intranet';
  $context->conditions = array(
    'sitewide' => array(
      'values' => array(
        '1' => 1,
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'atrium_intranet-account' => array(
          'module' => 'atrium_intranet',
          'delta' => 'account',
          'region' => 'header',
          'weight' => 0,
        ),
        'atrium_intranet-help' => array(
          'module' => 'atrium_intranet',
          'delta' => 'help',
          'region' => 'header',
          'weight' => 1,
        ),
        'atrium_intranet-spacelinks' => array(
          'module' => 'atrium_intranet',
          'delta' => 'spacelinks',
          'region' => 'space_tools',
          'weight' => 0,
        ),
        'atrium_intranet-create' => array(
          'module' => 'atrium_intranet',
          'delta' => 'create',
          'region' => 'space_tools',
          'weight' => 1,
        ),
        'xref-create' => array(
          'module' => 'xref',
          'delta' => 'create',
          'region' => 'page_tools',
          'weight' => 0,
        ),
      ),
    ),
  );

  $export['atrium-intranet-global'] = $context;
  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'theme-layout-custom';
  $context->description = '';
  $context->tag = 'Theme';
  $context->conditions = array();
  $context->reactions = array();

  $export['theme-layout-custom'] = $context;
  return $export;
}

/**
 * Helper to implementation of hook_ctools_plugin_api().
 */
function _atrium_intranet_ctools_plugin_api() {
  $args = func_get_args();
  $module = array_shift($args);
  $api = array_shift($args);
  if ($module == "context" && $api == "context") {
    return array("version" => 3);
  }
  else if ($module == "system" && $api == "strongarm") {
    return array("version" => 1);
  }
}

/**
 * Helper to implementation of hook_filter_default_formats().
 */
function _atrium_intranet_filter_default_formats() {
  $formats = array();

  // Exported format: Full HTML
  $formats[] = array(
    'name' => 'Full HTML',
    'roles' => array(
      '0' => 'admin',
      '1' => 'manager',
    ),
    'filters' => array(
      '0' => array(
        'module' => 'codefilter',
        'delta' => '0',
        'weight' => '0',
      ),
      '1' => array(
        'module' => 'filter',
        'delta' => '2',
        'weight' => '0',
      ),
      '2' => array(
        'module' => 'filter',
        'delta' => '1',
        'weight' => '1',
      ),
      '3' => array(
        'module' => 'filter',
        'delta' => '3',
        'weight' => '10',
      ),
    ),
  );

  // Exported format: Messaging plain text
  $formats[] = array(
    'name' => 'Messaging plain text',
    'roles' => array(),
    'filters' => array(
      '0' => array(
        'module' => 'filter',
        'delta' => '1',
        'weight' => '-10',
      ),
      '1' => array(
        'module' => 'messaging',
        'delta' => '1',
        'weight' => '-9',
      ),
    ),
  );

  // Exported format: Markdown
  $formats[] = array(
    'name' => 'Markdown',
    'roles' => array(
      '0' => 'anonymous user',
      '1' => 'authenticated user',
      '2' => 'admin',
      '3' => 'manager',
    ),
    'filters' => array(
      '0' => array(
        'module' => 'markdown',
        'delta' => '0',
        'weight' => '-10',
      ),
      '1' => array(
        'module' => 'filter',
        'delta' => '2',
        'weight' => '-9',
      ),
      '2' => array(
        'module' => 'filter',
        'delta' => '0',
        'weight' => '-8',
      ),
      '3' => array(
        'module' => 'codefilter',
        'delta' => '0',
        'weight' => '-7',
      ),
      '4' => array(
        'module' => 'filter',
        'delta' => '3',
        'weight' => '-6',
      ),
    ),
  );

  return $formats;
}

/**
 * Helper to implementation of hook_imagecache_default_presets().
 */
function _atrium_intranet_imagecache_default_presets() {
  $items = array(
    'fileview' => array(
      'presetname' => 'fileview',
      'actions' => array(
        '0' => array(
          'weight' => '0',
          'module' => 'imagecache',
          'action' => 'imagecache_deprecated_scale',
          'data' => array(
            'fit' => 'inside',
            'width' => '60',
            'height' => '40',
          ),
        ),
      ),
    ),
  );
  return $items;
}

/**
 * Helper to implementation of hook_user_default_permissions().
 */
function _atrium_intranet_user_default_permissions() {
  $permissions = array();

  // Exported permission: access administration pages
  $permissions[] = array(
    'name' => 'access administration pages',
    'roles' => array(
      '0' => 'admin',
    ),
  );

  // Exported permission: add list of open ids
  $permissions[] = array(
    'name' => 'add list of open ids',
    'roles' => array(
      '0' => 'admin',
    ),
  );

  // Exported permission: administer atrium
  $permissions[] = array(
    'name' => 'administer atrium',
    'roles' => array(
      '0' => 'admin',
    ),
  );

  // Exported permission: administer comments
  $permissions[] = array(
    'name' => 'administer comments',
    'roles' => array(
      '0' => 'admin',
      '1' => 'manager',
    ),
  );

  // Exported permission: administer filters
  $permissions[] = array(
    'name' => 'administer filters',
    'roles' => array(
      '0' => 'admin',
    ),
  );

  // Exported permission: administer messaging
  $permissions[] = array(
    'name' => 'administer messaging',
    'roles' => array(
      '0' => 'admin',
    ),
  );

  // Exported permission: administer nodes
  $permissions[] = array(
    'name' => 'administer nodes',
    'roles' => array(
      '0' => 'admin',
    ),
  );

  // Exported permission: administer notifications
  $permissions[] = array(
    'name' => 'administer notifications',
    'roles' => array(
      '0' => 'admin',
    ),
  );

  // Exported permission: administer permissions
  $permissions[] = array(
    'name' => 'administer permissions',
    'roles' => array(
      '0' => 'admin',
    ),
  );

  // Exported permission: administer search
  $permissions[] = array(
    'name' => 'administer search',
    'roles' => array(
      '0' => 'admin',
    ),
  );

  // Exported permission: administer site configuration
  $permissions[] = array(
    'name' => 'administer site configuration',
    'roles' => array(
      '0' => 'admin',
    ),
  );

  // Exported permission: administer spaces
  $permissions[] = array(
    'name' => 'administer spaces',
    'roles' => array(
      '0' => 'admin',
    ),
  );

  // Exported permission: administer taxonomy
  $permissions[] = array(
    'name' => 'administer taxonomy',
    'roles' => array(
      '0' => 'admin',
    ),
  );

  // Exported permission: post comments
  $permissions[] = array(
    'name' => 'post comments',
    'roles' => array(
      '0' => 'admin',
      '1' => 'authenticated user',
      '2' => 'manager',
    ),
  );

  // Exported permission: post comments without approval
  $permissions[] = array(
    'name' => 'post comments without approval',
    'roles' => array(
      '0' => 'admin',
      '1' => 'authenticated user',
      '2' => 'manager',
    ),
  );

  // Exported permission: revert revisions
  $permissions[] = array(
    'name' => 'revert revisions',
    'roles' => array(
      '0' => 'admin',
      '1' => 'manager',
    ),
  );

  // Exported permission: search content
  $permissions[] = array(
    'name' => 'search content',
    'roles' => array(
      '0' => 'admin',
      '1' => 'authenticated user',
      '2' => 'manager',
    ),
  );

  // Exported permission: select different theme
  $permissions[] = array(
    'name' => 'select different theme',
    'roles' => array(
      '0' => 'admin',
      '1' => 'authenticated user',
      '2' => 'manager',
    ),
  );

  // Exported permission: skip notifications
  $permissions[] = array(
    'name' => 'skip notifications',
    'roles' => array(
      '0' => 'admin',
      '1' => 'authenticated user',
      '2' => 'manager',
    ),
  );

  // Exported permission: subscribe other users
  $permissions[] = array(
    'name' => 'subscribe other users',
    'roles' => array(
      '0' => 'admin',
      '1' => 'authenticated user',
      '2' => 'manager',
    ),
  );

  // Exported permission: subscribe to author
  $permissions[] = array(
    'name' => 'subscribe to author',
    'roles' => array(
      '0' => 'admin',
      '1' => 'authenticated user',
      '2' => 'manager',
    ),
  );

  // Exported permission: subscribe to content
  $permissions[] = array(
    'name' => 'subscribe to content',
    'roles' => array(
      '0' => 'admin',
      '1' => 'authenticated user',
      '2' => 'manager',
    ),
  );

  // Exported permission: upload files
  $permissions[] = array(
    'name' => 'upload files',
    'roles' => array(
      '0' => 'admin',
      '1' => 'authenticated user',
      '2' => 'manager',
    ),
  );

  // Exported permission: upload files to comments
  $permissions[] = array(
    'name' => 'upload files to comments',
    'roles' => array(
      '0' => 'admin',
      '1' => 'authenticated user',
      '2' => 'manager',
    ),
  );

  // Exported permission: use advanced search
  $permissions[] = array(
    'name' => 'use advanced search',
    'roles' => array(
      '0' => 'admin',
      '1' => 'authenticated user',
      '2' => 'manager',
    ),
  );

  // Exported permission: view files uploaded to comments
  $permissions[] = array(
    'name' => 'view files uploaded to comments',
    'roles' => array(
      '0' => 'admin',
      '1' => 'authenticated user',
      '2' => 'manager',
    ),
  );

  // Exported permission: view imagecache fileview
  $permissions[] = array(
    'name' => 'view imagecache fileview',
    'roles' => array(
      '0' => 'admin',
      '1' => 'authenticated user',
      '2' => 'manager',
    ),
  );

  // Exported permission: view uploaded files
  $permissions[] = array(
    'name' => 'view uploaded files',
    'roles' => array(
      '0' => 'admin',
      '1' => 'authenticated user',
      '2' => 'manager',
    ),
  );

  return $permissions;
}

/**
 * Helper to implementation of hook_strongarm().
 */
function _atrium_intranet_strongarm() {
  $export = array();
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'allowed_html_5';
  $strongarm->value = '<div> <span> <br> <a> <em> <strong> <cite> <code> <strike> <ul> <ol> <li> <dl> <dt> <dd> <img> <blockquote> <p> <pre> <h1> <h2> <h3> <h4> <h5> <h6> <table> <caption> <thead> <th> <td> <tr> <sup> <sub>';

  $export['allowed_html_5'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'date_format_field_date_long';
  $strongarm->value = 'g:ia D M j, Y';

  $export['date_format_field_date_long'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'date_format_field_date_medium';
  $strongarm->value = 'g:ia M j, Y';

  $export['date_format_field_date_medium'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'date_format_field_date_short';
  $strongarm->value = 'M j, Y';

  $export['date_format_field_date_short'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'date_format_long';
  $strongarm->value = 'g:ia D M j, Y';

  $export['date_format_long'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'date_format_medium';
  $strongarm->value = 'g:ia M j, Y';

  $export['date_format_medium'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'date_format_short';
  $strongarm->value = 'M j, Y';

  $export['date_format_short'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'feedapi_allow_html_all';
  $strongarm->value = FALSE;

  $export['feedapi_allow_html_all'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'feedapi_allowed_html_tags';
  $strongarm->value = '<div> <h1> <h2> <h3> <h4> <h5> <h6> <img> <a> <b> <br> <dd> <dl> <dt> <em> <i> <li> <ol> <p> <strong> <u> <ul> <sup> <sub>';

  $export['feedapi_allowed_html_tags'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'feedapi_cron_percentage';
  $strongarm->value = '25';

  $export['feedapi_cron_percentage'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'filter_default_format';
  $strongarm->value = '5';

  $export['filter_default_format'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'imageapi_jpeg_quality';
  $strongarm->value = 90;

  $export['imageapi_jpeg_quality'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_primary_links_source';
  $strongarm->value = 'features';

  $export['menu_primary_links_source'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'messaging_default_method';
  $strongarm->value = 'mail';

  $export['messaging_default_method'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'messaging_method_mail';
  $strongarm->value = array(
    'filter' => 3,
  );

  $export['messaging_method_mail'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'notifications_content_per_type';
  $strongarm->value = 1;

  $export['notifications_content_per_type'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'notifications_team_max_options';
  $strongarm->value = 200;

  $export['notifications_team_max_options'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'notifications_ui_account_options';
  $strongarm->value = array(
    'block' => 'block',
  );

  $export['notifications_ui_account_options'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'notifications_ui_node';
  $strongarm->value = array(
    'block' => 'block',
  );

  $export['notifications_ui_node'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'notifications_ui_per_type';
  $strongarm->value = 0;

  $export['notifications_ui_per_type'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'notifications_ui_types';
  $strongarm->value = array(
    'grouptype' => 'grouptype',
    'thread' => 'thread',
    'nodetype' => 'nodetype',
    'author' => 'author',
  );

  $export['notifications_ui_types'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'notifications_ui_user';
  $strongarm->value = array(
    'page' => 'page',
  );

  $export['notifications_ui_user'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'seed_imagecache_attachment';
  $strongarm->value = 'fileview';

  $export['seed_imagecache_attachment'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'site_frontpage';
  $strongarm->value = 'welcome';

  $export['site_frontpage'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'spaces_features';
  $strongarm->value = array(
    'atrium_calendar' => '0',
    'atrium_groups' => '1',
    'atrium_intranet' => '1',
    'atrium_members' => '1',
  );

  $export['spaces_features'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'upload_extensions_2';
  $strongarm->value = 'au avi bzip2 csv doc docx flv gif graffle gz htm html iso jpeg jpg kml kmz mov mp2 mp3 mp4 odp ods odt pages patch pdf png pps ppt pptx psd rar svg swf template tif tgz txt vsd wav wmv xls xlsx zip';

  $export['upload_extensions_2'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'upload_extensions_3';
  $strongarm->value = 'au avi bzip2 csv doc docx flv gif graffle gz htm html iso jpeg jpg kml kmz mov mp2 mp3 mp4 odp ods odt pages patch pdf png pps ppt pptx psd rar svg swf template tif tgz txt vsd wav wmv xls xlsx zip';

  $export['upload_extensions_3'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'upload_extensions_4';
  $strongarm->value = 'au avi bzip2 csv doc docx flv gif graffle gz htm html iso jpeg jpg kml kmz mov mp2 mp3 mp4 odp ods odt pages patch pdf png pps ppt pptx psd rar svg swf template tif tgz txt vsd wav wmv xls xlsx zip';

  $export['upload_extensions_4'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'upload_extensions_default';
  $strongarm->value = 'au avi bzip2 csv doc docx flv gif graffle gz htm html iso jpeg jpg kml kmz mov mp2 mp3 mp4 odp ods odt pages patch pdf png pps ppt pptx psd rar svg swf template tif tgz txt vsd wav wmv xls xlsx zip';

  $export['upload_extensions_default'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'upload_list_default';
  $strongarm->value = 1;

  $export['upload_list_default'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'upload_uploadsize_2';
  $strongarm->value = 20;

  $export['upload_uploadsize_2'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'upload_uploadsize_3';
  $strongarm->value = 20;

  $export['upload_uploadsize_3'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'upload_uploadsize_4';
  $strongarm->value = 20;

  $export['upload_uploadsize_4'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'upload_uploadsize_default';
  $strongarm->value = 20;

  $export['upload_uploadsize_default'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'upload_usersize_2';
  $strongarm->value = 200;

  $export['upload_usersize_2'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'upload_usersize_3';
  $strongarm->value = 500;

  $export['upload_usersize_3'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'upload_usersize_4';
  $strongarm->value = 500;

  $export['upload_usersize_4'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'upload_usersize_default';
  $strongarm->value = 200;

  $export['upload_usersize_default'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'views_no_hover_links';
  $strongarm->value = TRUE;

  $export['views_no_hover_links'] = $strongarm;
  return $export;
}