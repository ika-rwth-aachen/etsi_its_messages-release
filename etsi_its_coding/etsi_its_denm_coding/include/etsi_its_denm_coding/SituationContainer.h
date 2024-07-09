/*
 * Generated by asn1c-0.9.29-DF (http://lionet.info/asn1c)
 * From ASN.1 module "DENM-PDU-Descriptions"
 * 	found in "/input/DENM-PDU-Descriptions.asn"
 * 	`asn1c -fcompound-names -no-gen-example -gen-UPER`
 */


/* Including external dependencies */
#include "etsi_its_denm_coding/InformationQuality.h"
#include "etsi_its_denm_coding/CauseCode.h"
#include <etsi_its_denm_coding/constr_SEQUENCE.h>
#ifndef	_SituationContainer_H_
#define	_SituationContainer_H_


#include <etsi_its_denm_coding/asn_application.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct CauseCode;
struct EventHistory;

/* SituationContainer */
typedef struct SituationContainer {
	InformationQuality_t	 informationQuality;
	CauseCode_t	 eventType;
	struct CauseCode	*linkedCause;	/* OPTIONAL */
	struct EventHistory	*eventHistory;	/* OPTIONAL */
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} SituationContainer_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_SituationContainer;
extern asn_SEQUENCE_specifics_t asn_SPC_SituationContainer_specs_1;
extern asn_TYPE_member_t asn_MBR_SituationContainer_1[4];

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "etsi_its_denm_coding/CauseCode.h"
#include "etsi_its_denm_coding/EventHistory.h"

#endif	/* _SituationContainer_H_ */
#include <etsi_its_denm_coding/asn_internal.h>
