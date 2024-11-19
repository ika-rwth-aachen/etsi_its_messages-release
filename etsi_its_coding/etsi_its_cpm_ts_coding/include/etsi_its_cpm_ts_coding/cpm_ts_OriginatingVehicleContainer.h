/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "CPM-OriginatingStationContainers"
 * 	found in "/input/CPM-OriginatingStationContainers.asn"
 * 	`asn1c -fcompound-names -fprefix=cpm_ts_ -no-gen-BER -no-gen-XER -no-gen-JER -no-gen-OER -no-gen-example -gen-UPER`
 */

#ifndef	_cpm_ts_OriginatingVehicleContainer_H_
#define	_cpm_ts_OriginatingVehicleContainer_H_


#include <etsi_its_cpm_ts_coding/asn_application.h>

/* Including external dependencies */
#include "etsi_its_cpm_ts_coding/cpm_ts_Wgs84Angle.h"
#include <etsi_its_cpm_ts_coding/constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct cpm_ts_CartesianAngle;
struct cpm_ts_TrailerDataSet;

/* cpm_ts_OriginatingVehicleContainer */
typedef struct cpm_ts_OriginatingVehicleContainer {
	cpm_ts_Wgs84Angle_t	 orientationAngle;
	struct cpm_ts_CartesianAngle	*pitchAngle;	/* OPTIONAL */
	struct cpm_ts_CartesianAngle	*rollAngle;	/* OPTIONAL */
	struct cpm_ts_TrailerDataSet	*trailerDataSet;	/* OPTIONAL */
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} cpm_ts_OriginatingVehicleContainer_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_cpm_ts_OriginatingVehicleContainer;
extern asn_SEQUENCE_specifics_t asn_SPC_cpm_ts_OriginatingVehicleContainer_specs_1;
extern asn_TYPE_member_t asn_MBR_cpm_ts_OriginatingVehicleContainer_1[4];

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "etsi_its_cpm_ts_coding/cpm_ts_CartesianAngle.h"
#include "etsi_its_cpm_ts_coding/cpm_ts_TrailerDataSet.h"

#endif	/* _cpm_ts_OriginatingVehicleContainer_H_ */
#include <etsi_its_cpm_ts_coding/asn_internal.h>
