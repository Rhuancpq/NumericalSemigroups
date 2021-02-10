PowerCoeffs := function(pol, n, mem)
    # mem should be a dict
    # Example of mem
    # mem := NewDictionary(Int, true, List);
    local res, t;
    if n = 1 then
        return pol;
    fi;

    if n mod 2 = 0 then
        t := n/2;
    else
        t := n-1;
    fi;

    if KnowsDictionary(mem, t) then
        res := LookupDictionary(mem, t);
    else
        res := PowerCoeffs(pol, t, mem);
        AddDictionary(mem, t, res);
    fi;

    if n mod 2 = 0 then
        return ProductCoeffs(res, res);
    else
        return ProductCoeffs(res, pol);
    fi;
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
    # Set need to be a Gap set of numericalsgps
    local g, nhs, n, res, mem;
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