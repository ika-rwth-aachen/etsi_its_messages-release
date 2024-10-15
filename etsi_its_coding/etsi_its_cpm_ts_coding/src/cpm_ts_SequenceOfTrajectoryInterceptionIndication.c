/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "ETSI-ITS-CDD"
 * 	found in "/input/ETSI-ITS-CDD.asn"
 * 	`asn1c -fcompound-names -fprefix=cpm_ts_ -no-gen-BER -no-gen-XER -no-gen-JER -no-gen-OER -no-gen-example -gen-UPER`
 */

#include "etsi_its_cpm_ts_coding/cpm_ts_SequenceOfTrajectoryInterceptionIndication.h"

#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
static asn_per_constraints_t asn_PER_type_cpm_ts_SequenceOfTrajectoryInterceptionIndication_constr_1 CC_NOTUSED = {
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	{ APC_CONSTRAINED | APC_EXTENSIBLE,  3,  3,  1,  8 }	/* (SIZE(1..8,...)) */,
	0, 0	/* No PER value map */
};
#endif  /* !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT) */
static asn_TYPE_member_t asn_MBR_cpm_ts_SequenceOfTrajectoryInterceptionIndication_1[] = {
	{ ATF_POINTER, 0, 0,
		(ASN_TAG_CLASS_UNIVERSAL | (16 << 2)),
		0,
		&asn_DEF_cpm_ts_TrajectoryInterceptionIndication,
		0,
		{
#if !defined(ASN_DISABLE_OER_SUPPORT)
			0,
#endif  /* !defined(ASN_DISABLE_OER_SUPPORT) */
#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
			0,
#endif  /* !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT) */
#if !defined(ASN_DISABLE_JER_SUPPORT)
			0,
#endif  /* !defined(ASN_DISABLE_JER_SUPPORT) */
			0
		},
		0, 0, /* No default value */
		""
		},
};
static const ber_tlv_tag_t asn_DEF_cpm_ts_SequenceOfTrajectoryInterceptionIndication_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static asn_SET_OF_specifics_t asn_SPC_cpm_ts_SequenceOfTrajectoryInterceptionIndication_specs_1 = {
	sizeof(struct cpm_ts_SequenceOfTrajectoryInterceptionIndication),
	offsetof(struct cpm_ts_SequenceOfTrajectoryInterceptionIndication, _asn_ctx),
	0,	/* XER encoding is XMLDelimitedItemList */
};
asn_TYPE_descriptor_t asn_DEF_cpm_ts_SequenceOfTrajectoryInterceptionIndication = {
	"SequenceOfTrajectoryInterceptionIndication",
	"SequenceOfTrajectoryInterceptionIndication",
	&asn_OP_SEQUENCE_OF,
	asn_DEF_cpm_ts_SequenceOfTrajectoryInterceptionIndication_tags_1,
	sizeof(asn_DEF_cpm_ts_SequenceOfTrajectoryInterceptionIndication_tags_1)
		/sizeof(asn_DEF_cpm_ts_SequenceOfTrajectoryInterceptionIndication_tags_1[0]), /* 1 */
	asn_DEF_cpm_ts_SequenceOfTrajectoryInterceptionIndication_tags_1,	/* Same as above */
	sizeof(asn_DEF_cpm_ts_SequenceOfTrajectoryInterceptionIndication_tags_1)
		/sizeof(asn_DEF_cpm_ts_SequenceOfTrajectoryInterceptionIndication_tags_1[0]), /* 1 */
	{
#if !defined(ASN_DISABLE_OER_SUPPORT)
		0,
#endif  /* !defined(ASN_DISABLE_OER_SUPPORT) */
#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
		&asn_PER_type_cpm_ts_SequenceOfTrajectoryInterceptionIndication_constr_1,
#endif  /* !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT) */
#if !defined(ASN_DISABLE_JER_SUPPORT)
		0,
#endif  /* !defined(ASN_DISABLE_JER_SUPPORT) */
		SEQUENCE_OF_constraint
	},
	asn_MBR_cpm_ts_SequenceOfTrajectoryInterceptionIndication_1,
	1,	/* Single element */
	&asn_SPC_cpm_ts_SequenceOfTrajectoryInterceptionIndication_specs_1	/* Additional specs */
};

