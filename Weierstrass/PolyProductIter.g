LoadPackage("Numericalsgps");;

PowerCoeffs := function(pol, n, mem)
    # mem should be a dict
    # Example of mem
    # mem := NewDictionary(Int, true, List);
    local i, vec;

    vec := EmptyPlist(n);
    Add(vec, pol);
    AddDictionary(mem, 1, pol);

    for i in [2..n] do
        if KnowsDictionary(mem, i) then
            Add(vec, LookupDictionary(mem, i));
        else
            if n mod 2 = 0 then
                Add(vec, ProductCoeffs(vec[n/2], vec[n/2]));
            else
                Add(vec, ProductCoeffs(vec[n-1], vec[1]));
            fi;
            AddDictionary(mem, i, vec[i]);
        fi;
    od;

    return vec[n];
end;

GetPolyCoeffs := function(set)
    local x, max, vec;
    max := set[Length(set)]+1;
    vec := EmptyPlist(max);
    for x in [1..max] do
        Add(vec, 0);
    od;
    for x in set do
        vec[x+1] := 1;
    od;
    return vec;
end;

MulSetCardinality := function(set, n, mem) 
    # mem should be a dict
    # Example of mem
    # mem := NewDictionary(Int, true, List);
    local x, vec, power, count;

    vec := GetPolyCoeffs(set);

    power := PowerCoeffs(vec, n, mem);
    count := 0;
    for x in [1..Length(power)] do
        if power[x] > 0 then
            count := count + 1;
        fi;
    od;
    return count;
end;

BuchweitzTest := function(set, min, max)
    local g, nhs, n, res, mem;
    if not RepresentsGapsOfNumericalSemigroup(set) then
        Error("Set must be a gapset of a numericalsgps");
        return -1;
    fi;
    mem := NewDictionary(Int, true, List);
    g := Length(set);
    res := EmptyPlist(max-min+1);
    for n in [min..max] do
        nhs := MulSetCardinality(set, n, mem);

        if nhs > (2*n-1) * (g - 1) then
            Add(res, true);
        else
            Add(res, false);
        fi;
    od;

    return res;
end;