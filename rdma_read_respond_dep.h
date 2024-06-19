//
// Created by 熊嘉晟 on 2024/6/19.
//

#ifndef RDMA_READ_RESPOND_RDMA_READ_RESPOND_DEP_H
#define RDMA_READ_RESPOND_RDMA_READ_RESPOND_DEP_H


#include <doca_error.h>
#include <doca_log.h>
#include <doca_buf_inventory.h>
#include <doca_buf.h>
#include <doca_ctx.h>
#include <cstring>

#include "rdma_common.h"


/*
 * Write the connection details and the mmap details for the requester to read,
 * and read the connection details of the requester
 *
 * @cfg [in]: Configuration parameters
 * @resources [in/out]: RDMA resources
 * @return: DOCA_SUCCESS on success and DOCA_ERROR otherwise
 */
doca_error_t write_read_connection(struct rdma_config *cfg, struct rdma_resources *resources);
/*
 * Export and receive connection details, and connect to the remote RDMA
 *
 * @resources [in]: RDMA resources
 * @return: DOCA_SUCCESS on success and DOCA_ERROR otherwise
 */
doca_error_t rdma_read_responder_export_and_connect(struct rdma_resources *resources);

/*
 * RDMA read responder state change callback
 * This function represents the state machine for this RDMA program
 *
 * @user_data [in]: doca_data from the context
 * @ctx [in]: DOCA context
 * @prev_state [in]: Previous DOCA context state
 * @next_state [in]: Next DOCA context state
 */
void rdma_read_responder_state_change_callback(const union doca_data user_data,
                                                      struct doca_ctx *ctx,
                                                      enum doca_ctx_states prev_state,
                                                      enum doca_ctx_states next_state);

/*
 * Responder side of the RDMA read
 *
 * @cfg [in]: Configuration parameters
 * @return: DOCA_SUCCESS on success and DOCA_ERROR otherwise
 */
doca_error_t rdma_read_responder(struct rdma_config *cfg);


#endif //RDMA_READ_RESPOND_RDMA_READ_RESPOND_DEP_H
