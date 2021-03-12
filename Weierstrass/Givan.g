LoadPackage("Numericalsgps");

GivanTest := function(ming, maxg, maxn)
    local g, gap, gaps, sns, count, lg, n;
    for g in [ming..maxg] do
        sns := NumericalSemigroupsWithGenus(g);
        gaps := List(sns, x -> GapsOfNumericalSemigroup(x));
        Print("Gênero: ", g, "\n");
        Print("Numero de gapsets: ", Length(gaps), "\n");
        for n in [2..maxn] do
            count := 0;
            for gap in gaps do
                lg := gap[Length(gap)];
                if(lg >= 2*g-1-Int(g/n)) then
                    count := count+1;
                fi;
                
            od;
           
            Print("n: ", n, "\n");
            Print("Quantos satisfazem: ", count, "\n\n");
        od;
        Print("-----------------------------\n\n");
    od;
end;

GivanTestCSV := function(ming, maxg, maxn)
    local g, x, gap, gaps, sns, hist, count, lg, n;
    Print("g, ng, ");
    for x in [2..maxn] do
        Print(x);
        if x <> maxn then
            Print(", ");
        else
            Print("\n");
        fi;
    od;
    for g in [ming..maxg] do
        sns := NumericalSemigroupsWithGenus(g);
        gaps := List(sns, x -> GapsOfNumericalSemigroup(x));
        Print(g, ", ");
        Print(Length(gaps), ", ");
        hist := EmptyPlist(maxn);
        for n in [1..maxn] do
            hist[n] := 0;
        od;
        for gap in gaps do
            lg := gap[Length(gap)];
            for n in [2..maxn] do
                if(Float(lg) >= Float(2*g-1)-Float(g/n)) then
                    hist[n] := hist[n]+1;
                fi;
            od;
        od;
        for n in [2..maxn] do
            Print(hist[n]);
            if n <> maxn then
                Print(", ");
            else
                Print("\n");
            fi; 
        od;
    od;
end;