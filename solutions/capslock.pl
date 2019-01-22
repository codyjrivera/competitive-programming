$_ = <>;
tr/A-Za-z/a-zA-Z/ if /^[a-z]?[A-Z]*\s*$/;
print;
