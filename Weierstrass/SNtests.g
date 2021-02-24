Read("PolyProductIter.g");

BuchweitzFirstOfTest := function(set, max)
    local g, nhs, n, res, mem;
    if not RepresentsGapsOfNumericalSemigroup(set) then
        Error("Set must be a gapset of a numericalsgps");
        return -1;
    fi;
    mem := NewDictionary(Int, true, List);
    g := Length(set);
    for n in [2..max] do
        nhs := MulSetCardinality(set, n, mem);

        if nhs > (2*n-1) * (g - 1) then
            return [true, n];
        fi;
    od;

    return [false];
end;

SNTestsByGenus := function(ming, maxg, maxn)
    local g, x, sns, gaps, res;
    for g in [ming..maxg] do
        sns := NumericalSemigroupsWithGenus(g);
        gaps := List(sns, x -> GapsOfNumericalSemigroup(x));
        Print("SN by genus ", g, ":\n\n");
        for x in gaps do
            res := BuchweitzFirstOfTest(x, maxn);
            if res[1] then
                Print("gapset: ", x);
                Print(" n: ", res[2], "\n");
            fi;
        od;
        Print("\n");
    od;

end;