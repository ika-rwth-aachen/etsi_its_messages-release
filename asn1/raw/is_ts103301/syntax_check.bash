#!/bin/bash -e
# ----------------------------------------------------
# This script uses the Open Source asn1c to check all used ASN.1 modules
# are compile clean (no guarantee the generated code is valid).
#
# The used compile binary was built from here:
#   https://github.com/brchiu/asn1c/commits/velichkov_s1ap_plus_option_group_plus_adding_trailing_ull
#
# The referenced ISO ASN.1 modules are pulled from the ISO Standards Maintenance Portal
# Yet not all are compile clean, thus minor fixed need to be done.
# All these changes are irrelevant for the resulting encoding.
#  - Fixing duplicate DE tags
#  - Fixing OID typo
#  - Removing unused types (which bloat the IMPORTS)
# ----------------------------------------------------

# set -x

install -d build/asn1 build/spatem build/ivim

if [ ! -f build/asn1/ISO-TS-19091-addgrp-C-2018.asn ]; then
  wget -P build/asn1 https://standards.iso.org/iso/ts/19091/ed-2/en/ISO-TS-19091-addgrp-C-2018.asn
  sed -e 's/\bHeadingConfidence\b/HeadingConfidenceDSRC/g' \
      -e 's/\bSpeedConfidence\b/SpeedConfidenceDSRC/g' \
      -e 's/\bHeading\b/HeadingDSRC/g' \
  	  build/asn1/ISO-TS-19091-addgrp-C-2018.asn > build/asn1/ISO-TS-19091-addgrp-C-2018-patched.asn
fi
if [ ! -f 'build/asn1/ISO19321(2019)IVIv2.asn' ]; then
  wget -P build/asn1 'https://standards.iso.org/iso/ts/19321/ed-2/en/ISO19321IVIv2.asn'
fi
if [ ! -f build/asn1/ISO24534-3_ElectronicRegistrationIdentificationVehicleDataModule_ForBallot.asn ]; then
  wget -P build/asn1 'https://standards.iso.org/iso/24534/-3/ISO%2024534-3%20ASN.1%20repository/ISO24534-3_ElectronicRegistrationIdentificationVehicleDataModule_ForBallot.asn'
fi
if [ ! -f build/asn1/ISO14816_AVIAEINumberingAndDataStructures.asn ]; then
  wget -P build/asn1 https://standards.iso.org/iso/14816/ISO14816%20ASN.1%20repository/ISO14816_AVIAEINumberingAndDataStructures.asn
fi
if [ ! -f 'build/asn1/ISO14906(2018)EfcDsrcApplicationv6.asn' ]; then
  wget -P build/asn1 'https://standards.iso.org/iso/14906/ed-3/en/ISO14906(2018)EfcDsrcApplicationv6.asn'
fi
if [ ! -f 'build/asn1/ISO14906(2018)EfcDsrcGenericv7.asn' ]; then
  wget -P build/asn1 'https://standards.iso.org/iso/14906/ed-3/en/ISO14906(2018)EfcDsrcGenericv7.asn'
fi
if [ ! -f 'build/asn1/TS17419_2014_CITSapplMgmtIDs.asn' ]; then
  wget -P build/asn1 'https://standards.iso.org/iso/ts/17419/TS%2017419%20ASN.1%20repository/TS17419_2014_CITSapplMgmtIDs.asn'
fi
if [ ! -f 'build/asn1/ISO14906(2018)EfcDsrcGenericv7.asn' ]; then
  wget -P build/asn1 'https://standards.iso.org/iso/14906/ed-3/en/ISO14906(2018)EfcDsrcGenericv7.asn'
fi

install -d build/ivim
asn1c -D build/ivim -R -no-gen-example -fcompound-names \
	'IVIM-PDU-Descriptions.asn' \
	'cdd/ITS-Container.asn' \
	'iso-patched/ISO24534-3_ElectronicRegistrationIdentificationVehicleDataModule-patched.asn' \
	'iso-patched/ISO14823-missing.asn' \
	'build/asn1/TS17419_2014_CITSapplMgmtIDs.asn' \
	'iso-patched/ISO14906(2018)EfcDsrcGenericv7-patched.asn' \
	'iso-patched/ISO14906(2018)EfcDsrcApplicationv6-patched.asn' \
	'build/asn1/ISO-TS-19091-addgrp-C-2018-patched.asn' \
	'build/asn1/ISO14816_AVIAEINumberingAndDataStructures.asn' \
	'build/asn1/ISO19321IVIv2.asn' \

install -d build/spatem
asn1c -D build/spatem -R -no-gen-example -fcompound-names \
	SPATEM-PDU-Descriptions.asn \
	cdd/ITS-Container.asn \
	iso-patched/ISO24534-3_ElectronicRegistrationIdentificationVehicleDataModule-patched.asn \
	build/asn1/ISO-TS-19091-addgrp-C-2018-patched.asn \
	build/asn1/ISO14816_AVIAEINumberingAndDataStructures.asn \

install -d build/mapem
asn1c -D build/mapem -R -no-gen-example -fcompound-names \
	MAPEM-PDU-Descriptions.asn \
	cdd/ITS-Container.asn \
	iso-patched/ISO24534-3_ElectronicRegistrationIdentificationVehicleDataModule-patched.asn \
	build/asn1/ISO-TS-19091-addgrp-C-2018-patched.asn \
	build/asn1/ISO14816_AVIAEINumberingAndDataStructures.asn \

install -d build/srem
asn1c -D build/srem -R -no-gen-example -fcompound-names \
	SREM-PDU-Descriptions.asn \
	cdd/ITS-Container.asn \
	iso-patched/ISO24534-3_ElectronicRegistrationIdentificationVehicleDataModule-patched.asn \
	build/asn1/ISO-TS-19091-addgrp-C-2018-patched.asn \
	build/asn1/ISO14816_AVIAEINumberingAndDataStructures.asn \

install -d build/ssem
asn1c -D build/ssem -R -no-gen-example -fcompound-names \
	SSEM-PDU-Descriptions.asn \
	cdd/ITS-Container.asn \
	iso-patched/ISO24534-3_ElectronicRegistrationIdentificationVehicleDataModule-patched.asn \
	build/asn1/ISO-TS-19091-addgrp-C-2018-patched.asn \
	build/asn1/ISO14816_AVIAEINumberingAndDataStructures.asn \

install -d build/rtcmem
asn1c -D build/rtcmem -R -no-gen-example -fcompound-names \
	RTCMEM-PDU-Descriptions.asn \
	cdd/ITS-Container.asn \
	iso-patched/ISO24534-3_ElectronicRegistrationIdentificationVehicleDataModule-patched.asn \
	build/asn1/ISO-TS-19091-addgrp-C-2018-patched.asn \
	build/asn1/ISO14816_AVIAEINumberingAndDataStructures.asn \

echo "++++++++++++++++++++++++"
echo "+++ SUCCESS"
echo "+++ All modules compiled"
echo "++++++++++++++++++++++++"
