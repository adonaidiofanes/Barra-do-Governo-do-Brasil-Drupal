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
      '#default_value' => variable_get('barra_gov_cor'),
  );
  
  $form['#submit'][] = 'barra_gov_admin_settings_submit';
  return system_settings_form($form);
  
}

/**
 * Validate annotation settings submission.
 */
function barra_gov_admin_settings_validate($form, &$form_state) {

}

/**
 * barra_gov_admin_settings_validate
 */
function barra_gov_admin_settings_submit($form, $form_state){
  
  //drupal_set_message($form['barra_gov']['barra_gov_color']['#value']);
  
  variable_set('barra_gov_cor', $form['barra_gov']['barra_gov_color']['#value']);
  
  drupal_set_message( variable_get('barra_gov_cor') );
 
  //dpm($form);
  
  
}
