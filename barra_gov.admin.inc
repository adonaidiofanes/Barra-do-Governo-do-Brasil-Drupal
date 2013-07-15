<?php

/**
 * @file
 * callbacks da página de administração para o módulo Barra do Governo do Brasil.
 */

/**
 * Construtor de formulário. Configura anotações.
 * 
 * @ingroup forms
 * @see system_settings_form().
 */

function barra_gov_admin_settings(){
  // Obtém um array de tipos de nodes com nomes internos como chaves e
  // "nomes simpáticos" como valores. Por exemplo,
  // array('page' => 'Página básica', 'article' => 'Artigos')
  /*
  $types = node_type_get_types();
  
  foreach ($types as $node_type){
    $options[$node_type->type] = $node_type->name;
  }*/
  
  $form['barra_gov'] = array(
     '#type' => 'fieldset',
     '#title' => t('Configuração Visual'),
   );
  
  $form['barra_gov']['barra_gov_color'] = array(
      '#type' => 'select',
      '#title' => t('Cor de Fundo'),
      '#description' => t('Escolha uma das opções para cor de fundo da barra.'),
      '#options' => array(
          t('Verde'),
          t('Cinza'),
          t('Preto'),
          t('Azul'),
      ),
      '#default_value' => 'Azul',
      //'#default_value' => variable_get('barra_gov_node_types', array('page')),
  );
  
  /*$form['barra_gov_deletion'] = array(
    '#type' => 'radios',
    '#title' => t('Anotações a serem excluidas'),
    '#description' => t('Selecione o método que você deseja excluir.'),
    '#options' => array(
      t('Never'),
      t('Randomly'),
      t('After 30 days')
    ),
  '#default_value' => variable_get('barra_gov_deletion', 0) // Default to Never
  );
  
  $form['barra_gov_limit_per_node'] = array(
    '#type' => 'textfield',
    '#title' => t('Anotações por node'),
    '#description' => t('Enter the maximum number of annotations allowed per node (0 for no limit).'),
    '#default_value' => variable_get('barra_gov_limit_per_node', 1),
    '#size' => 3
  );*/
  
  $form['#submit'][] = 'barra_gov_admin_settings_submit';
  return system_settings_form($form);
  
}

/**
 * Validate annotation settings submission.
 */
function barra_gov_admin_settings_validate($form, &$form_state) {
  /*
  $limit = $form_state['values']['barra_gov_limit_per_node'];
  if (!is_numeric($limit)) {
    form_set_error('barra_gov_limit_per_node', t('Please enter number.'));
  }
  */
}

/**
 * barra_gov_admin_settings_validate
 */
function barra_gov_admin_settings_submit($form, $form_state){
  // varre todas as caixas de seleção do tipo de conteúdo mostradas no formulário
 /* foreach($form_state['values']['barra_gov_node_types'] as $key => $value){
    // se a caixa de seleção para um tipo de conteúdo estiver desmarcada, verifica, usando a função field_info_instance
    // Se este tipo de conteúdo tem o campo de anotações associado a ele. Se tiver é necessário removero campo de anotações, pois o administrador desmarcou a caixa de seleção.
    if(!$value){
      $instance = field_info_instance('node','anotacao', $key);
      if(!empty($instance)){
       
        // field_delete_instance($instance);
        // fonte: #20 - http://www.drupalbook.com/errata3
        field_delete_instance($instance);
        watchdog("Anotacao", 'Deleted annotation field from content type:
          %key', array('%key' => $key));
      } // fim de anotação existia, é preciso removê-la.
    } else {
      // Se a caixa de seleção estiver marcada para um tipo de conteúdo, é verificado se o campo está associado àquele tipo de conteúdo. Se não estiver, o campo de anotações é adicionado ao tipo de conteúdo.
      $instance = field_info_instance('node', 'anotacao', $key);
      if(empty($instance)){
        $instance = array(
          'field_name' => 'anotacao',
          'entity_type' => 'node',
          'bundle' => $key,
          'label' => t('Anotação'),
          'widget_type' => 'text_textarea_with_summary',
          'settings' => array('display_summary' => TRUE),
          'display' => array(
            'default' => array(
              'type' => 'text_default',
            ),
            'teaser' => array(
              'type' => 'text_summary_or_trimmed',
            ),
        ),
      );
        
        $instance = field_create_instance($instance);
        //watchdog("anotacao", "Added anotacao field to content type:% " . $key);
        // https://drupal.org/node/1191846
        watchdog('Anotacao', 'Added annotation field to content type: %key',
        array('%key' => $key));
        
      } // fim de campo de anotações não existia; deve ser adicionado
    } // fim do if
  }*/
}
