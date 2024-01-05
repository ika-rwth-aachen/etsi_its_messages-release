/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "CAM-PDU-Descriptions"
 * 	found in "/input/CAM-PDU-Descriptions.asn"
 * 	`asn1c -fcompound-names -no-gen-example -gen-PER`
 */

#ifndef	_SpecialTransportContainer_H_
#define	_SpecialTransportContainer_H_


#include <etsi_its_cam_coding/asn_application.h>

/* Including external dependencies */
#include "etsi_its_cam_coding/SpecialTransportType.h"
#include "etsi_its_cam_coding/LightBarSirenInUse.h"
#include <etsi_its_cam_coding/constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* SpecialTransportContainer */
typedef struct SpecialTransportContainer {
	SpecialTransportType_t	 specialTransportType;
	LightBarSirenInUse_t	 lightBarSirenInUse;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} SpecialTransportContainer_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_SpecialTransportContainer;
extern asn_SEQUENCE_specifics_t asn_SPC_SpecialTransportContainer_specs_1;
extern asn_TYPE_member_t asn_MBR_SpecialTransportContainer_1[2];

#ifdef __cplusplus
}
#endif

#endif	/* _SpecialTransportContainer_H_ */
#include <etsi_its_cam_coding/asn_internal.h>
