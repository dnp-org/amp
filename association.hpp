struct Association
{
    Role our_role_; // master or outstation
    optional<string> remote_common_name_;
    optional<Certificate> remote_certificate_;
    optional<RoutingTable> remote_routing_table_; // needed if we're the master
    SecurityProfile security_profile_; // require session layer, allow skipping the session layer, don't use the session layer
};

bool canEstablishTrustAndValidateMessages(Association const &association) {
    return true
        && "we have the remote common name (either from configuration or from the remote certificate)"
        && "we have the remote certificate"
        && "we trust the remote certificate"
        ;
}

bool stuck(Association const &association) {
    return false
        || !canEstablishTrustAndValidateMessages(association)
        ;
}

bool downstream(Association const &association) {
    return "we are the master";
}

bool upstream(Association cosnt &association) {
    return !downstream(association);
}

bool ready(Association const &association) {
    return true
        && (true
            && downstream(association)
            && canEstablishTrustAndValidateMessages(association)
            && "the routing table is downloaded"
           )
        || (true
            && upsteam(association)
            && canEstablishTrustAndValidateMessages(association)
            && "we've notified the master of our restart"
           )
        ;
}

bool authorityReachable(Association const &association) {
    return true
        && upstream(association)
        && (false
            || "this is the designated association to communicate with the Authority over"
            || "we have received a message from the Authority over this association"
            )
}

