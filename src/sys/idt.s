.global idtLoad
.extern idtp
idtLoad:
        lidt (idtp)
        ret
