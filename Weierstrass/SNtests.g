Read("PolyProductIter.g");

BuchweitzFirstOfTest := function(set, max)
    local g, nhs, n, res, mem, lg;
    if not RepresentsGapsOfNumericalSemigroup(set) then
        Error("Set must be a gapset of a numericalsgps");
        return -1;
    fi;
    mem := NewDictionary(Int, true, List);
    g := Length(set);
    for n in [2..max] do
        # Gilvan theorem
        lg := set[g];
        if(lg >= 2*g-1-Int(g/n)) then
            nhs := MulSetCardinality(set, n, mem);

            if nhs > (2*n-1) * (g - 1) then
                return [true, n];
            fi;
        else 
            continue;
        fi;
    od;

    return [false];
end;

BuchweitzPassTestMultipleTimes := function(set, max)
    local g, nhs, n, res, mem, lg;
    if not RepresentsGapsOfNumericalSemigroup(set) then
        Error("Set must be a gapset of a numericalsgps");
        return -1;
    fi;
    mem := NewDictionary(Int, true, List);
    res := [];
    g := Length(set);
    for n in [2..max] do
        # Gilvan theorem
        lg := set[g];
        if(lg >= 2*g-1-Int(g/n)) then
            nhs := MulSetCardinality(set, n, mem);

            if nhs > (2*n-1) * (g - 1) then
                Add(res, n);
            fi;
        fi;
    od;
    
    return res;
end;

SNTestsByGenus := function(ming, maxg, maxn)
    local g, x, sns, gaps, res, vec, fn;
    for g in [ming..maxg] do
        sns := NumericalSemigroupsWithGenus(g);
        gaps := List(sns, x -> GapsOfNumericalSemigroup(x));
        Print("SN by genus ", g, ":\n\n");
        vec := [];
        for x in gaps do
            res := BuchweitzFirstOfTest(x, maxn);
            if res[1] then
                Add(vec, [x, res[2]]);
            fi;
        od;

        if Length(vec) > 0 then
            fn := function(a, b)
                return a[2] < b[2];
            end;

            StableSort(vec, fn);

            for x in vec do
                Print("gapset: ", x[1], " n: ", x[2], "\n");
            od;
        fi;
        Print("\n");
    od;

end;

SNTestsTwiceByGenus := function(ming, maxg, maxn)
    local g, x, y, sns, gaps, res, vec, fn;
    for g in [ming..maxg] do
        sns := NumericalSemigroupsWithGenus(g);
        gaps := List(sns, x -> GapsOfNumericalSemigroup(x));
        Print("SN by genus ", g, ":\n\n");
        vec := [];
        for x in gaps do
            res := BuchweitzPassTestMultipleTimes(x, maxn);
            if Length(res) > 1 then
                Add(vec, [x, res]);
            fi;
        od;

        if Length(vec) > 0 then
            fn := function(a, b)
                return a[2][1] < b[2][1];
            end;

            StableSort(vec, fn);

            for x in vec do
                Print("gapset: ", x[1], " n: ");
                for y in x[2] do
                    Print(y, " ");
                od;
                Print("\n"); 
            od;
        fi;
        Print("\n");
    od;
end;