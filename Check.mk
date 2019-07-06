DIRECTORY_MAP := \
	out \
	out/arch \
	out/arch/${ARCH}

out/out_check:
	mkdir -p ${DIRECTORY_MAP}
	touch out/out_check
	
