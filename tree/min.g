LoadPackage("Numericalsgps");

for g in [0..4] do
    sns := NumericalSemigroupsWithGenus(g);
    for x in sns do
        Print(List(MinimalGenerators(x))    , "\n");
    od;
    Print("\n");
od;