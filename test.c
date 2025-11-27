int main() {

  int sum = 0;
  for (int i = 0; i < 100; i++) {

    sum += i;
  }

  return 0;
}

/* (let* ((proj (project-current)) */
/*          (root (project-root proj)) */
/*          (src  (buffer-file-name)) */
/*          (exe  (concat root */
/*                   (file-name-base src))) */
/*        ) */

/*         (dap-register-debug-template */
/*                             "C++ Debug Current file" */
/*                               (list :type "cppdbg" */
/*          :request "launch" */
/*          :name "Debug current file" */
/*          :stopAtEntry t */
/*          :MIMode "gdb" */
/*          :program exe */
/*          :cwd root)) */

/*  ) */
