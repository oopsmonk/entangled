IOTA CClient Library
======================

An IOTA client library implementation in C language, aka iota.c. 
The C library is able to run on a small device that supports full TCP/IP stack. 

`CClient Github`_

Example projects for IoT application: 

* `iota_esp32_wallet`_: IOTA Wallet application.
* `iota_esp32_cashier`_: A portable payment device.
* `tangle_pigeon_esp32`_: TanglePigeon carries a message to the Tangle.


.. _CClient Github: https://github.com/iotaledger/entangled/tree/develop/cclient
.. _iota_esp32_wallet: https://github.com/oopsmonk/iota_esp32_wallet
.. _iota_esp32_cashier: https://github.com/oopsmonk/iota_esp32_cashier
.. _tangle_pigeon_esp32: https://github.com/oopsmonk/tangle_pigeon_esp32


Getting Start 
---------------

Before using client APIs, you need to initialize client service.
Here shows how to call `getNodeInfo`_ in CClient.
More details please see: `cclient_example`_

.. code-block:: c

  retcode_t ret = RC_ERROR;
  iota_client_service_t serv;
  serv.http.path = "/";
  serv.http.content_type = "application/json";
  serv.http.accept = "application/json";
  // IRI endpoint
  serv.http.host = "nodes.thetangle.org";
  // IRI API port number
  serv.http.port = 443;
  serv.http.api_version = 1;
  serv.serializer_type = SR_JSON;
  // needed for HTTPS
  serv.http.ca_pem = amazon_ca1_pem;

  // initialize core APIs
  iota_client_core_init(&serv);

  // initialize extended APIs
  iota_client_extended_init();

  // new and check the response object
  get_node_info_res_t *node_res = get_node_info_res_new();
  if (node_res == NULL) {
    printf("Error: OOM\n");
    return;
  }

  // calls getNodeInfo
  ret = iota_client_get_node_info(s, node_res);
  printf("%s", error_2_string(ret));

  // clean up
  get_node_info_res_free(&node_res);
  iota_client_extended_destroy();
  iota_client_core_destroy(&serv);


.. _getNodeInfo: https://docs.iota.org/docs/node-software/0.1/iri/references/api-reference#getnodeinfo
.. _cclient_example: https://github.com/oopsmonk/entangled/blob/develop/cclient/api/examples/cclient_examples.c#L35


Client Service 
-----------------

.. doxygenfile:: cclient/service.h
   :project: Entangled


Core APIs
--------------

* `iota_client_add_neighbors`_ 
* `iota_client_attach_to_tangle`_ 
* `iota_client_broadcast_transactions`_ 
* `iota_client_check_consistency`_ 
* `iota_client_find_transactions`_ 
* `iota_client_get_balances`_ 
* `iota_client_get_inclusion_states`_ 
* `iota_client_get_neighbors`_ 
* `iota_client_get_node_api_conf`_ 
* `iota_client_get_node_info`_ 
* `iota_client_get_tips`_
* `iota_client_get_transactions_to_approve`_ 
* `iota_client_get_trytes`_ 
* `iota_client_remove_neighbors`_ 
* `iota_client_store_transactions`_ 
* `iota_client_were_addresses_spent_from`_

.. _iota_client_add_neighbors: #c.iota_client_add_neighbors
.. _iota_client_attach_to_tangle: #c.iota_client_attach_to_tangle
.. _iota_client_broadcast_transactions: #c.iota_client_broadcast_transactions
.. _iota_client_check_consistency: #c.iota_client_check_consistency
.. _iota_client_find_transactions: #c.iota_client_find_transactions
.. _iota_client_get_balances: #c.iota_client_get_balances
.. _iota_client_get_inclusion_states: #c.iota_client_get_inclusion_states
.. _iota_client_get_neighbors: #c.iota_client_get_neighbors
.. _iota_client_get_node_api_conf: #c.iota_client_get_node_api_conf
.. _iota_client_get_node_info: #c.iota_client_get_node_info
.. _iota_client_get_tips: #c.iota_client_get_tips
.. _iota_client_get_transactions_to_approve: #c.iota_client_get_transactions_to_approve
.. _iota_client_get_trytes: #c.iota_client_get_trytes
.. _iota_client_remove_neighbors: #c.iota_client_remove_neighbors
.. _iota_client_store_transactions: #c.iota_client_store_transactions
.. _iota_client_were_addresses_spent_from: #c.iota_client_were_addresses_spent_from

.. doxygenfunction:: iota_client_add_neighbors
   :project: Entangled
   :path: cclient/api/core

.. doxygenfunction:: iota_client_attach_to_tangle 
   :project: Entangled
   :path: cclient/api/core

`example_attach_to_tangle`_ 

.. _example_attach_to_tangle: https://github.com/oopsmonk/entangled/blob/develop/cclient/api/examples/example_attach_to_tangle.c

.. doxygenfunction:: iota_client_broadcast_transactions
   :project: Entangled
   :path: cclient/api/core

`example_broadcast_transactions`_ 

.. _example_broadcast_transactions: https://github.com/oopsmonk/entangled/blob/develop/cclient/api/examples/example_broadcast_transactions.c

.. doxygenfunction:: iota_client_check_consistency
   :project: Entangled
   :path: cclient/api/core

`example_check_consistency`_ 

.. _example_check_consistency: https://github.com/oopsmonk/entangled/blob/develop/cclient/api/examples/example_check_consistency.c

.. doxygenfunction:: iota_client_find_transactions
   :project: Entangled
   :path: cclient/api/core

`example_find_transactions`_ 

.. _example_find_transactions: https://github.com/oopsmonk/entangled/blob/develop/cclient/api/examples/example_find_transactions.c

.. doxygenfunction:: iota_client_get_balances 
   :project: Entangled
   :path: cclient/api/core

`example_get_balance`_ 

.. _example_get_balance: https://github.com/oopsmonk/entangled/blob/develop/cclient/api/examples/example_get_balance.c

.. doxygenfunction:: iota_client_get_inclusion_states
   :project: Entangled
   :path: cclient/api/core

`example_get_inclusion_states`_ 

.. _example_get_inclusion_states: https://github.com/oopsmonk/entangled/blob/develop/cclient/api/examples/example_get_inclusion_states.c

.. doxygenfunction:: iota_client_get_neighbors
   :project: Entangled
   :path: cclient/api/core

.. doxygenfunction:: iota_client_get_node_api_conf 
   :project: Entangled
   :path: cclient/api/core

`example_node_api_conf`_ 

.. _example_node_api_conf: https://github.com/oopsmonk/entangled/blob/develop/cclient/api/examples/example_node_api_conf.c

.. doxygenfunction:: iota_client_get_node_info 
   :project: Entangled
   :path: cclient/api/core

`example_node_info`_ 

.. _example_node_info: https://github.com/oopsmonk/entangled/blob/develop/cclient/api/examples/example_node_info.c

.. doxygenfunction:: iota_client_get_tips
   :project: Entangled
   :path: cclient/api/core

`example_get_tips`_ 

.. _example_get_tips: https://github.com/oopsmonk/entangled/blob/develop/cclient/api/examples/example_get_tips.c

.. doxygenfunction:: iota_client_get_transactions_to_approve
   :project: Entangled
   :path: cclient/api/core

`example_get_transactions_to_approve`_ 

.. _example_get_transactions_to_approve: https://github.com/oopsmonk/entangled/blob/develop/cclient/api/examples/example_get_transactions_to_approve.c

.. doxygenfunction:: iota_client_get_trytes
   :project: Entangled
   :path: cclient/api/core

`example_get_trytes`_ 

.. _example_get_trytes: https://github.com/oopsmonk/entangled/blob/develop/cclient/api/examples/example_get_trytes.c

.. doxygenfunction:: iota_client_remove_neighbors
   :project: Entangled
   :path: cclient/api/core

.. doxygenfunction:: iota_client_store_transactions
   :project: Entangled
   :path: cclient/api/core
 
`example_store_transactions`_ 

.. _example_store_transactions: https://github.com/oopsmonk/entangled/blob/develop/cclient/api/examples/example_store_transactions.c

.. doxygenfunction:: iota_client_were_addresses_spent_from 
   :project: Entangled
   :path: cclient/api/core

`example_were_addresses_spent_from`_ 

.. _example_were_addresses_spent_from: https://github.com/oopsmonk/entangled/blob/develop/cclient/api/examples/example_were_addresses_spent_from.c



Extended APIs
----------------

* `iota_client_broadcast_bundle`_ 
* `iota_client_find_transaction_objects`_ 
* `iota_client_get_account_data`_ 
* `iota_client_get_bundle`_ 
* `iota_client_get_inputs`_ 
* `iota_client_get_latest_inclusion`_ 
* `iota_client_get_new_address`_ 
* `iota_client_get_transaction_objects`_ 
* `iota_client_is_promotable`_ 
* `iota_client_prepare_transfers`_ 
* `iota_client_promote_transaction`_ 
* `iota_client_replay_bundle`_ 
* `iota_client_send_transfer`_ 
* `iota_client_send_trytes`_ 
* `iota_client_store_and_broadcast`_ 
* `iota_client_traverse_bundle`_ 

.. _iota_client_broadcast_bundle: #c.iota_client_broadcast_bundle
.. _iota_client_find_transaction_objects: #c.iota_client_find_transaction_objects
.. _iota_client_get_account_data: #c.iota_client_get_account_data
.. _iota_client_get_bundle: #c.iota_client_get_bundle
.. _iota_client_get_inputs: #c.iota_client_get_inputs
.. _iota_client_get_latest_inclusion: #c.iota_client_get_latest_inclusion
.. _iota_client_get_new_address: #c.iota_client_get_new_address
.. _iota_client_get_transaction_objects: #c.iota_client_get_transaction_objects
.. _iota_client_is_promotable: #c.iota_client_is_promotable
.. _iota_client_prepare_transfers: #c.iota_client_prepare_transfers
.. _iota_client_promote_transaction: #c.iota_client_promote_transaction
.. _iota_client_replay_bundle: #c.iota_client_replay_bundle
.. _iota_client_send_transfer: #c.iota_client_send_transfer
.. _iota_client_send_trytes: #c.iota_client_send_trytes
.. _iota_client_store_and_broadcast: #c.iota_client_store_and_broadcast
.. _iota_client_traverse_bundle: #c.iota_client_traverse_bundle


.. doxygenfunction:: iota_client_broadcast_bundle
   :project: Entangled
   :path: cclient/api/extended

`example_broadcast_bundle`_ 

.. _example_broadcast_bundle: https://github.com/oopsmonk/entangled/blob/develop/cclient/api/examples/example_broadcast_bundle.c

.. doxygenfunction:: iota_client_find_transaction_objects
   :project: Entangled
   :path: cclient/api/extended

`example_find_transaction_objects`_ 

.. _example_find_transaction_objects: https://github.com/oopsmonk/entangled/blob/develop/cclient/api/examples/example_find_transaction_objects.c

.. doxygenfunction:: iota_client_get_account_data
   :project: Entangled
   :path: cclient/api/extended

`example_get_account_data`_ 

.. _example_get_account_data: https://github.com/oopsmonk/entangled/blob/develop/cclient/api/examples/example_get_account_data.c

.. doxygenstruct:: account_data_t
   :project: Entangled
   :path: cclient/api/extended
   :members:

.. doxygenfunction:: iota_client_get_bundle
   :project: Entangled
   :path: cclient/api/extended

`example_get_bundle`_ 

.. _example_get_bundle: https://github.com/oopsmonk/entangled/blob/develop/cclient/api/examples/example_get_bundle.c


.. doxygenfunction:: iota_client_get_inputs
   :project: Entangled
   :path: cclient/api/extended

`example_get_inputs`_ 

.. _example_get_inputs: https://github.com/oopsmonk/entangled/blob/develop/cclient/api/examples/example_get_inputs.c

.. doxygenfunction:: iota_client_get_latest_inclusion
   :project: Entangled
   :path: cclient/api/extended

`example_get_latest_inclusion`_ 

.. _example_get_latest_inclusion: https://github.com/oopsmonk/entangled/blob/develop/cclient/api/examples/example_get_latest_inclusion.c

.. doxygenfunction:: iota_client_get_new_address
   :project: Entangled
   :path: cclient/api/extended

`example_get_new_address`_ 

.. _example_get_new_address: https://github.com/oopsmonk/entangled/blob/develop/cclient/api/examples/example_get_new_address.c

.. doxygenfunction:: iota_client_get_transaction_objects
   :project: Entangled
   :path: cclient/api/extended

.. doxygenfunction:: iota_client_is_promotable
   :project: Entangled
   :path: cclient/api/extended

`example_is_promotable`_ 

.. _example_is_promotable: https://github.com/oopsmonk/entangled/blob/develop/cclient/api/examples/example_is_promotable.c

.. doxygenfunction:: iota_client_prepare_transfers
   :project: Entangled
   :path: cclient/api/extended

`example_prepare_transfer`_ 

.. _example_prepare_transfer: https://github.com/oopsmonk/entangled/blob/develop/cclient/api/examples/example_prepare_transfer.c

.. doxygenfunction:: iota_client_promote_transaction
   :project: Entangled
   :path: cclient/api/extended

`example_promote_transacion`_ 

.. _example_promote_transacion: https://github.com/oopsmonk/entangled/blob/develop/cclient/api/examples/example_promote_transacion.c

.. doxygenfunction:: iota_client_replay_bundle
   :project: Entangled
   :path: cclient/api/extended

`example_replay_bundle`_ 

.. _example_replay_bundle: https://github.com/oopsmonk/entangled/blob/develop/cclient/api/examples/example_replay_bundle.c

.. doxygenfunction:: iota_client_send_transfer
   :project: Entangled
   :path: cclient/api/extended

.. doxygenfunction:: iota_client_send_trytes
   :project: Entangled
   :path: cclient/api/extended

`example_send_trytes`_ 

.. _example_send_trytes: https://github.com/oopsmonk/entangled/blob/develop/cclient/api/examples/example_send_trytes.c

.. doxygenfunction:: iota_client_store_and_broadcast
   :project: Entangled
   :path: cclient/api/extended

.. doxygenfunction:: iota_client_traverse_bundle
   :project: Entangled
   :path: cclient/api/extended

`example_traverse_bundle`_ 

.. _example_traverse_bundle: https://github.com/oopsmonk/entangled/blob/develop/cclient/api/examples/example_traverse_bundle.c

Requests
----------

.. doxygenfile:: cclient/request/add_neighbors.h
   :project: Entangled

.. doxygenfile:: cclient/request/attach_to_tangle.h
   :project: Entangled

.. doxygenfile:: cclient/request/broadcast_transactions.h
   :project: Entangled

.. doxygenfile:: cclient/request/check_consistency.h
   :project: Entangled

.. doxygenfile:: cclient/request/find_transactions.h
   :project: Entangled

.. doxygenfile:: cclient/request/get_balances.h
   :project: Entangled

.. doxygenfile:: cclient/request/get_inclusion_states.h
   :project: Entangled

.. doxygenfile:: cclient/request/get_transactions_to_approve.h
   :project: Entangled

.. doxygenfile:: cclient/request/get_trytes.h
   :project: Entangled

.. doxygenfile:: cclient/request/remove_neighbors.h
   :project: Entangled

.. doxygenfile:: cclient/request/store_transactions.h
   :project: Entangled

.. doxygenfile:: cclient/request/were_addresses_spent_from.h
   :project: Entangled

Responses
------------

.. doxygenfile:: cclient/response/add_neighbors.h
   :project: Entangled

.. doxygenfile:: cclient/response/attach_to_tangle.h
   :project: Entangled

.. doxygenfile:: cclient/response/check_consistency.h
   :project: Entangled

.. doxygenfile:: cclient/response/error.h
   :project: Entangled

.. doxygenfile:: cclient/response/find_transactions.h
   :project: Entangled

.. doxygenfile:: cclient/response/get_balances.h
   :project: Entangled

.. doxygenfile:: cclient/response/get_inclusion_states.h
   :project: Entangled

.. doxygenfile:: cclient/response/get_missing_transactions.h
   :project: Entangled

.. doxygenfile:: cclient/response/get_neighbors.h
   :project: Entangled

.. doxygenfile:: cclient/response/get_node_api_conf.h
   :project: Entangled

.. doxygenfile:: cclient/response/get_node_info.h
   :project: Entangled

.. doxygenfile:: cclient/response/get_tips.h
   :project: Entangled

.. doxygenfile:: cclient/response/get_transactions_to_approve.h
   :project: Entangled

.. doxygenfile:: cclient/response/get_trytes.h
   :project: Entangled

.. doxygenfile:: cclient/response/remove_neighbors.h
   :project: Entangled

.. doxygenfile:: cclient/response/were_addresses_spent_from.h
   :project: Entangled
