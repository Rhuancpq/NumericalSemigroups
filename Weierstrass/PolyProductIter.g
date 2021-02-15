LoadPackage("Numericalsgps");;

PowerCoeffs := function(pol, n, mem)
    # mem should be a dict
    # Example of mem
    # mem := NewDictionary(Int, true, List);
    local i, res, x, y;

    i := n;
    x := pol;
    y := [1];

    if KnowsDictionary(mem, n) then
        return LookupDictionary(mem, n);        
    fi;

    while(i > 1) do
        if i mod 2 = 0 then
            x := ProductCoeffs(x, x);
            i := i/2;
        else
            y := ProductCoeffs(x, y);
            x := ProductCoeffs(x, x);
            i := (i-1)/2;
        fi;
            
    od;

    res := ProductCoeffs(x, y);
    AddDictionary(mem, n, res);
    
    return res;
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