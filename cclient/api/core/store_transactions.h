/*
 * Copyright (c) 2019 IOTA Stiftung
 * https://github.com/iotaledger/entangled
 *
 * Refer to the LICENSE file for licensing information
 */

/**
 * @ingroup cclient_core
 *
 * @{
 *
 * @file
 * @brief
 *
 */
#ifndef CCLIENT_API_STORE_TRANSACTIONS_H
#define CCLIENT_API_STORE_TRANSACTIONS_H

#include "cclient/http/http.h"
#include "cclient/request/store_transactions.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Store transactions in an IRI node's local storage.
 *
 * The trytes must be validated by #iota_client_attach_to_tangle
 *
 * @param[in] service client service
 * @param[in] req List of transaction trytes
 * @return #retcode_t
 */
retcode_t iota_client_store_transactions(iota_client_service_t const* const service,
                                         store_transactions_req_t const* const req);

#ifdef __cplusplus
}
#endif

#endif  // CCLIENT_API_STORE_TRANSACTIONS_H

/** @} */