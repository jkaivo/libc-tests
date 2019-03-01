#!/usr/bin/awk -f

/type/ {
	printf("static %s a_%s;\n\n", $2, $2);
}

/distinct/ {
	printf("static int %s[] = {\n", $2);
	for (i = 3; i < NF; i++) {
		#printf("#ifndef %s\n", $i);
		#printf("#error %s not defined\n", $i);
		#printf("#endif\n");
		printf("\t%s,\n", $i);
	}
	printf("};\n");
}
