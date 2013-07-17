<?php

/**
 * @file
 * Menu builder functions for Barra do Governo do Brasil. 
 */

/**
 * 
 * @ingroup forms
 * @see system_settings_form().
 */

function barra_gov_admin_settings(){
  
  $form['barra_gov'] = array(
     '#type' => 'fieldset',
     '#title' => t('Configuração Visual'),
   );
  
  $options = array(
    
    'verde' => t('Verde'),
    'cinza' => t('Cinza'),
    'preto' => t('Preto'),
    'azul'  => t('Azul')

  );
  
  $form['barra_gov']['barra_gov_color'] = array(
      '#type' => 'select',
      '#title' => t('Cor de Fundo'),
      '#description' => t('Escolha uma das opções para cor de fundo da barra.'),
      '#options' => $options,
      '#required' => TRUE,
      '#default_value' => variable_get('barra_gov_color'),
  );
  
  $form['#submit'][] = 'barra_gov_admin_settings_submit';
  return system_settings_form($form);
  
}

/**
 * barra_gov_admin_settings_validate
 */
function barra_gov_admin_settings_submit($form, $form_state){
  
  variable_set('barra_gov_color', $form['barra_gov']['barra_gov_color']['#value']);
  
  drupal_set_message( t('The visual configuration was set to ') . variable_get('barra_gov_color') . '.' );
  
}
