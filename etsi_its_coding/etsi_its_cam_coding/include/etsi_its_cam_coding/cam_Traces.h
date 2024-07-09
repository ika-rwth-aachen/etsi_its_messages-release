/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "ITS-Container"
 * 	found in "/input/ITS-Container.asn"
 * 	`asn1c -fcompound-names -fprefix=cam_ -no-gen-BER -no-gen-XER -no-gen-JER -no-gen-OER -no-gen-example -gen-UPER`
 */

#ifndef	_cam_Traces_H_
#define	_cam_Traces_H_


#include <etsi_its_cam_coding/asn_application.h>

/* Including external dependencies */
#include <etsi_its_cam_coding/asn_SEQUENCE_OF.h>
#include <etsi_its_cam_coding/constr_SEQUENCE_OF.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct cam_PathHistory;

/* cam_Traces */
typedef struct cam_Traces {
	A_SEQUENCE_OF(struct cam_PathHistory) list;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} cam_Traces_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_cam_Traces;

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "etsi_its_cam_coding/cam_PathHistory.h"

#endif	/* _cam_Traces_H_ */
#include <etsi_its_cam_coding/asn_internal.h>