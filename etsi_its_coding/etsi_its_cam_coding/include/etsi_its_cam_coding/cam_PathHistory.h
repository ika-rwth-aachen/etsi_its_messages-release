/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "ITS-Container"
 * 	found in "/input/ITS-Container.asn"
 * 	`asn1c -fcompound-names -fprefix=cam_ -no-gen-BER -no-gen-XER -no-gen-JER -no-gen-OER -no-gen-example -gen-UPER`
 */

#ifndef	_cam_PathHistory_H_
#define	_cam_PathHistory_H_


#include <etsi_its_cam_coding/asn_application.h>

/* Including external dependencies */
#include <etsi_its_cam_coding/asn_SEQUENCE_OF.h>
#include <etsi_its_cam_coding/constr_SEQUENCE_OF.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct cam_PathPoint;

/* cam_PathHistory */
typedef struct cam_PathHistory {
	A_SEQUENCE_OF(struct cam_PathPoint) list;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} cam_PathHistory_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_cam_PathHistory;
extern asn_SET_OF_specifics_t asn_SPC_cam_PathHistory_specs_1;
extern asn_TYPE_member_t asn_MBR_cam_PathHistory_1[1];
extern asn_per_constraints_t asn_PER_type_cam_PathHistory_constr_1;

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "etsi_its_cam_coding/cam_PathPoint.h"

#endif	/* _cam_PathHistory_H_ */
#include <etsi_its_cam_coding/asn_internal.h>
