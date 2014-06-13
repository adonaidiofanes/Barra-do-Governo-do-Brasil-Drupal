<?php

/**
 * @file
 * Admin functions for Barra do Governo do Brasil module.
 */

/**
 * Admin form for barra_gov module.
 * @ingroup forms.
 * @see system_settings_form()
 */
function barra_gov_admin_settings() {

  $form['barra_gov'] = array(
    '#type' => 'fieldset',
    '#title' => t('Information about the electoral period'),
  );

  $form['barra_gov']['information'] = array(
    '#markup' => t('<p>The Secretariat of Social Communication of the Presidency-circular letter sent to all government departments indicating the conduits for the election period, including the use of the Federal Government brand.</p> <p>Please pay attention to the guidelines found in the link: <a target="_blank" href="http://www.secom.gov.br/orientacoes-gerais/normas-e-contratacoes/eleicoes-2014_/saiba-sobre-as-eleicoes-2014">http://www.secom.gov.br/orientacoes-gerais/normas-e-contratacoes/eleicoes-2014_/saiba-sobre-as-eleicoes-2014</a></p>')
  );

   return system_settings_form($form);
  
}
