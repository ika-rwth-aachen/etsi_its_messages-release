/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "DENM-PDU-Descriptions"
 * 	found in "/input/DENM-PDU-Descriptions.asn"
 * 	`asn1c -fcompound-names -fprefix=denm_ -no-gen-BER -no-gen-XER -no-gen-JER -no-gen-OER -no-gen-example -gen-UPER`
 */

#ifndef	_denm_DecentralizedEnvironmentalNotificationMessage_H_
#define	_denm_DecentralizedEnvironmentalNotificationMessage_H_


#include <etsi_its_denm_coding/asn_application.h>

/* Including external dependencies */
#include "etsi_its_denm_coding/denm_ManagementContainer.h"
#include <etsi_its_denm_coding/constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct denm_SituationContainer;
struct denm_LocationContainer;
struct denm_AlacarteContainer;

/* denm_DecentralizedEnvironmentalNotificationMessage */
typedef struct denm_DecentralizedEnvironmentalNotificationMessage {
	denm_ManagementContainer_t	 management;
	struct denm_SituationContainer	*situation;	/* OPTIONAL */
	struct denm_LocationContainer	*location;	/* OPTIONAL */
	struct denm_AlacarteContainer	*alacarte;	/* OPTIONAL */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} denm_DecentralizedEnvironmentalNotificationMessage_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_denm_DecentralizedEnvironmentalNotificationMessage;
extern asn_SEQUENCE_specifics_t asn_SPC_denm_DecentralizedEnvironmentalNotificationMessage_specs_1;
extern asn_TYPE_member_t asn_MBR_denm_DecentralizedEnvironmentalNotificationMessage_1[4];

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "etsi_its_denm_coding/denm_SituationContainer.h"
#include "etsi_its_denm_coding/denm_LocationContainer.h"
#include "etsi_its_denm_coding/denm_AlacarteContainer.h"

#endif	/* _denm_DecentralizedEnvironmentalNotificationMessage_H_ */
#include <etsi_its_denm_coding/asn_internal.h>
