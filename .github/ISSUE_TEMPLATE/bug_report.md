name: Bug Report
description: File a bug report
labels: [bug, to-review]
body:
- type: dropdown
  attributes:
    label: Operating System
    description: Known operating system where the bug has occured.
    id: os
    multiple: true
    options:
    - Windows
    - macOS
    - Linux
- type: textarea
  attributes:
    label: Steps to reproduce
    description: List step by step how to reproduce this bug.
    placeholder: "* Create a new instance..."
  validations:
    required: true
- type: textarea
  attributes:
    label: Description
    description: Explain what happened.
    placeholder: I can't start an instance when I...
  validations:
    required: true
- type: textarea
  attributes:
    label: Suspected cause
    description: Describe what is the cause of the bug if you have an idea.
  validations:
    required: false
