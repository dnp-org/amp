Parsing an AMPPDU
=================
1. validate the `version` field (type, length and value): it should correspond to the ASN.1 syntax's version (which, when the official version is out, will be `1`. If absent, it may be assumed to be valid but if present, it shall correspond to a version the implementation supports.
2. validate the `sequenceNumber` field (type, length and value): it shall either be absent or be something other than `0`. If it is present and something other than `0`, store it for use with the response for the message (or, if you're parsing the response, it shall match the sequence number of the message being responded to -- though that can't be validated at this point yet).
3. validate the `targetName` field (type, length and value): it shall either be present and correspond to a device name, or absent, in which case the message is targeted to the Authority. If targeted to the Authority, the signature can only be verified by the Authority itself. If targeted at a device, the signature can, and shall, be verified.
4. If validating the signature, concatenate the DER-encoded fields preceding the signature, and use it for signature verification.

Implementations SHALL verify the signature if the message is addressed to them or if the message originates with the Authority.
