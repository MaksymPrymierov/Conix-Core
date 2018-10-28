.global idtLoad
.extern idtp
idtLoad:
	lidt (idtp)
	sti
	ret
