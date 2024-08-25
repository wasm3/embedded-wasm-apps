(module
  (type $t0 (func (param i32 i32)))
  (type $t1 (func))
  (type $t2 (func (param i32)))

  ;; Wiring imports
  (import "wiring" "print" (func $print (type $t0)))
  (import "wiring" "pinMode" (func $pinMode (type $t0)))
  (import "wiring" "digitalWrite" (func $digitalWrite (type $t0)))
  (import "wiring" "delay" (func $delay (type $t2)))

  ;; Memory
  (memory (export "memory") 1)
  (data (i32.const 16) "\e2\9a\99\ef\b8\8f WAT is running!\0a")
  (data (i32.const 48) "Blink\0a")

  ;; Functions
  (func (export "setup") (type $t1)
    (call $print (i32.const 16) (i32.const 23))     ;; Welcome message

    (call $pinMode (i32.const 2) (i32.const 1))
  )
  (func (export "loop") (type $t1)
    (call $print (i32.const 48) (i32.const 6))      ;; Blink

    (call $digitalWrite (i32.const 2) (i32.const 1))
    (call $delay (i32.const 100))
    (call $digitalWrite (i32.const 2) (i32.const 0))
    (call $delay (i32.const 900))
  )
)
