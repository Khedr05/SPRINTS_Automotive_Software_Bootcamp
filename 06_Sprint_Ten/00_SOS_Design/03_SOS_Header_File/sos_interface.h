/*
 * sos_interface.h
 *
 * Created: 29/05/2023 17:38:26
 *  Author: 20101
 */ 


#ifndef SOS_INTERFACE_H_
#define SOS_INTERFACE_H_

#define TASKS_DATA_BASE_MAX_SIZE		10	

typedef enum
{
	SOS_STATUS_SUCCESS						= 0		,
	SOS_STATUS_INVALID_STATE						,
	SOS_STATUS_INITIALIZE							,
	SOS_STATUS_DEINITIALIZE							,
	SOS_STATUS_DISABLED_OK							,
	SOS_STATUS_DISABLED_NOK							, 
	TASK_STATUS_CREATE_OK							,
	TASK_STATUS_CREATE_NOK							,
	TASK_STATUS_DELETED_OK							,
	TASK_STATUS_DELETED_NOK							,
	TASK_STATUS_MODIFIED_OK							,
	TASK_STATUS_MODIFIED_NOK
}enu_system_status_t;

typedef enum
{
	TASK_STATUS_CREATED						= 0		,
	TASK_STATUS_DELETED								,
	TASK_STATUS_RUNNING								,
	TASK_STATUS_WAITING								,
	TASK_STATUS_DISABLED							,
	TASK_STATUS_IDLE	
}enu_task_status_t;


typedef struct  
{
	Uchar8_t			task_id									;	
	Uchar8_t			task_priority							;
	Uchar8_t			task_period_ms							;					
	enu_task_status_t	task_status								;
	void				(*ptr_func_task_run)		(void)		;
}str_task_instance_t;

typedef struct
{
	enu_system_status_t		sos_general_status							;
	str_task_instance_t    *sos_data_base[TASKS_DATA_BASE_MAX_SIZE]		;
	
}str_sos_instance_t;


enu_system_status_t  sos_init			(void)									;
enu_system_status_t  sos_deinit			(void)									;
enu_system_status_t	 sos_create_task	(str_task_instance_t *ptr_str_task)		;
enu_system_status_t	 sos_delete_task	(Uchar8_t copy_u8_task_id)				;
enu_system_status_t	 sos_modify_task	(str_task_instance_t *ptr_str_task)		;
enu_system_status_t	 sos_disable		(void)									;
void				 sos_run			(void)									;


#endif /* SOS_INTERFACE_H_ */