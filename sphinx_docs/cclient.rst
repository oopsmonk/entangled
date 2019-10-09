IOTA CClient Library
======================

An IOTA client library implementation in C language.

Core APIs
--------------

.. doxygenfunction:: iota_client_add_neighbors
   :project: Entangled
   :path: cclient/api/core

.. doxygenfunction:: iota_client_attach_to_tangle 
   :project: Entangled
   :path: cclient/api/core

.. doxygenfunction:: iota_client_broadcast_transactions
   :project: Entangled
   :path: cclient/api/core

.. doxygenfunction:: iota_client_check_consistency
   :project: Entangled
   :path: cclient/api/core

.. doxygenfunction:: iota_client_find_transactions
   :project: Entangled
   :path: cclient/api/core

.. doxygenfunction:: iota_client_get_balances 
   :project: Entangled
   :path: cclient/api/core

.. doxygenfunction:: iota_client_get_inclusion_states
   :project: Entangled
   :path: cclient/api/core

.. doxygenfunction:: iota_client_get_neighbors
   :project: Entangled
   :path: cclient/api/core

.. doxygenfunction:: iota_client_get_node_info 
   :project: Entangled
   :path: cclient/api/core

.. doxygenfunction:: iota_client_get_tips
   :project: Entangled
   :path: cclient/api/core

.. doxygenfunction:: iota_client_get_transactions_to_approve
   :project: Entangled
   :path: cclient/api/core

.. doxygenfunction:: iota_client_get_trytes
   :project: Entangled
   :path: cclient/api/core

.. doxygenfunction:: iota_client_remove_neighbors
   :project: Entangled
   :path: cclient/api/core

.. doxygenfunction:: iota_client_store_transactions
   :project: Entangled
   :path: cclient/api/core

.. doxygenfunction:: iota_client_were_addresses_spent_from 
   :project: Entangled
   :path: cclient/api/core

Extended APIs
----------------

.. doxygenfunction:: iota_client_broadcast_bundle
   :project: Entangled
   :path: cclient/api/extended

.. doxygenfunction:: iota_client_find_transaction_objects
   :project: Entangled
   :path: cclient/api/extended

.. doxygenfunction:: iota_client_get_account_data
   :project: Entangled
   :path: cclient/api/extended

.. doxygenstruct:: account_data_t
   :project: Entangled
   :path: cclient/api/extended
   :members:

.. doxygenfunction:: iota_client_get_bundle
   :project: Entangled
   :path: cclient/api/extended

.. doxygenfunction:: iota_client_get_inputs
   :project: Entangled
   :path: cclient/api/extended

.. doxygenfunction:: iota_client_get_latest_inclusion
   :project: Entangled
   :path: cclient/api/extended

.. doxygenfunction:: iota_client_get_new_address
   :project: Entangled
   :path: cclient/api/extended

.. doxygenfunction:: iota_client_get_transaction_objects
   :project: Entangled
   :path: cclient/api/extended

.. doxygenfunction:: iota_client_is_promotable
   :project: Entangled
   :path: cclient/api/extended

.. doxygenfunction:: iota_client_prepare_transfers
   :project: Entangled
   :path: cclient/api/extended

.. doxygenfunction:: iota_client_promote_transaction
   :project: Entangled
   :path: cclient/api/extended

.. doxygenfunction:: iota_client_replay_bundle
   :project: Entangled
   :path: cclient/api/extended

.. doxygenfunction:: iota_client_send_transfer
   :project: Entangled
   :path: cclient/api/extended

.. doxygenfunction:: iota_client_send_trytes
   :project: Entangled
   :path: cclient/api/extended

.. doxygenfunction:: iota_client_store_and_broadcast
   :project: Entangled
   :path: cclient/api/extended

.. doxygenfunction:: iota_client_traverse_bundle
   :project: Entangled
   :path: cclient/api/extended
