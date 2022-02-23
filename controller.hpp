struct Controller
{
    Certificate identity_certificate_;
    optional<Certificate> authority_certificate_;
    vector<Association> associations_;
    Policies policies_;
};

