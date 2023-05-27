/*
 * bcm_interface.h
 *
 * Created: 22/05/2023 21:57:37
 *  Author: 20101
 */ 


#ifndef BCM_INTERFACE_H_
#define BCM_INTERFACE_H_

#include "../../COMMON/std_types.h"
#include "bcm_cfg.h"


 

enu_bcm_states_code_t bcm_init(const str_bcm_instance_t * ptr_str_bcm_instance);

enu_bcm_states_code_t bcm_deinit(const str_bcm_instance_t * ptr_str_bcm_instance);

enu_bcm_states_code_t bcm_send(const str_bcm_instance_t * ptr_str_bcm_instance , Uchar8_t *copy_ptr_u8_data_to_send);

enu_bcm_states_code_t bcm_send_n(const str_bcm_instance_t * ptr_str_bcm_instance , Uchar8_t *copy_ptr_u8_data_to_send , Uint16_t copy_u8_number_of_bytes);

enu_bcm_states_code_t bcm_dispatcher(void);








#endif /* BCM_INTERFACE_H_ */