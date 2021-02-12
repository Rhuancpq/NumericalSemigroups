LoadPackage("Numericalsgps");;

SumTwoSet := function(A, B)
    local res, a, b;    
    res := Set([]);

    for a in A do
        for b in B do
            AddSet(res, a+b);
        od;
    od;

    return res;
end;

SumSet := function(A)
    local res, len, i, j;
    res := Set([]);
    len := Length(A);
    for i in [1..len] do
        for j in [i..len] do
            AddSet(res, A[i]+A[j]);
        od;
    od;

    return res;
end;

SumSetNary := function(set, n, mem) 
    # mem should be a dict
    # Example of mem
    # mem := NewDictionary(Int, true, Set);
    local res, t;
    if n = 1 then
        return set;
    fi;

    if n mod 2 = 0 then
        t := n/2;
    else
        t := (n-1)/2;
    fi;

    if KnowsDictionary(mem, t) then
        res := LookupDictionary(mem, t);
    else
        res := SumSetNary(set, t, mem);
        AddDictionary(mem, t, res);
    fi;

    if n mod 2 = 0 then
        return SumSet(res);
    else
        return SumTwoSet(SumSet(res), set);
    fi;
end;

BuchweitzTest := function(set, min, max)
    local g, nhs, n, res, mem;
    if not RepresentsGapsOfNumericalSemigroup(set) then
        Error("Set must be a gapset of a numericalsgps");
        return -1;
    fi;
    mem := NewDictionary(Int, true, Set);
    g := Length(set);
    res := EmptyPlist(max-min+1);
    for n in [min..max] do
        nhs := Length(SumSetNary(set, n, mem));

        if nhs > (2*n-1) * (g - 1) then
            Add(res, true);
        else
            Add(res, false);
        fi;
    od;

    return res;
end;