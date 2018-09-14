read_port:
  movl 4(%esp), %edx
  in %dx, %al
  ret

write_port:
  mov 4(%esp), %edx
  mov 8(%esp), %al
  out %al, %dx
  ret
