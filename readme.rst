.. |license| image:: https://img.shields.io/badge/License-Apache%202.0-3c60b1.svg?style=flat-square
   :target: https://github.com/quantumlib/Cirq/blob/main/LICENSE
   :alt: Licensed under the Apache 2.0 license

.. |python| image:: https://img.shields.io/badge/Python-3.10+-fd6d0c.svg?style=flat-square
   :target: https://www.python.org/downloads/
   :alt: Compatible with Python versions 3.10 and higher

.. |contributors| image:: https://img.shields.io/github/contributors/quantumlib/cirq?label=Contributors&style=flat-square&color=f9af06
   :target: https://github.com/quantumlib/Cirq/graphs/contributors
   :alt: GitHub contributors

.. |stars| image:: https://img.shields.io/github/stars/quantumlib/cirq?style=flat-square&logo=github&label=Stars&color=fd6d0c
   :target: https://github.com/quantumlib/cirq
   :alt: GitHub stars

.. |zenodo| image:: https://img.shields.io/badge/10.5281%2Fzenodo.4062499-gray.svg?label=DOI&style=flat-square&colorA=gray&colorB=3c60b1
   :target: https://doi.org/10.5281/zenodo.4062499
   :alt: Archived in Zenodo

.. |ci| image:: https://img.shields.io/github/actions/workflow/status/quantumlib/cirq/ci.yml?event=schedule&style=flat-square&logo=GitHub&label=Continuous%20Integration
   :target: https://github.com/quantumlib/Cirq/actions/workflows/ci-daily.yml
   :alt: Cirq continuous integration status

.. |codecov| image:: https://img.shields.io/codecov/c/github/quantumlib/cirq?style=flat-square&logo=codecov&label=Codecov
   :target: https://codecov.io/gh/quantumlib/Cirq
   :alt: Code coverage report

.. |pypi| image:: https://img.shields.io/pypi/v/cirq.svg?color=green&logo=python&logoColor=white&label=PyPI&style=flat-square
   :target: https://pypi.org/project/cirq
   :alt: Cirq project on PyPI
  
.. raw:: html

   <div align="center">
  
.. image:: https://raw.githubusercontent.com/quantumlib/Cirq/refs/heads/main/docs/images/Cirq_logo_color.svg
   :width: 280px
   :height: 135px
   :align: center
   :alt: Cirq logo

Python package for writing, manipulating, and running
`quantum circuits <https://en.wikipedia.org/wiki/Quantum_circuit>`_
on quantum computers and simulators.

| |license| |python| |contributors| |stars| |zenodo|
| |ci| |codecov| |pypi|

.. The following addition of <p> is deliberate.
.. raw:: html

   <p>

`Features <#features>`_ •
`Installation <#installation>`_ •
`“Hello Qubit” <#hello-qubit-example>`_ •
`Docs <#cirq-documentation>`_ •
`Integrations <#integrations>`_ •
`Community <#community>`_ •
`Citing Cirq <#citing-cirq>`_ •
`Contact <#contact>`_

.. raw:: html

   </p></div>

 
Features
--------

Cirq provides useful abstractions for dealing with today’s `noisy
intermediate-scale quantum <https://arxiv.org/abs/1801.00862>`_ (NISQ)
computers, where the details of quantum hardware are vital to achieving
state-of-the-art results. Some of its features include:

* Flexible gate definitions and custom gates
* Parametrized circuits with symbolic variables
* Circuit transformation, compilation and optimization
* Hardware device modeling
* Noise modeling
* Multiple built-in quantum circuit simulators
* Integration with `qsim <https://github.com/quantumlib/qsim>`_ for
  high-performance simulation
* Interoperability with `NumPy <https://numpy.org>`_ and
  `SciPy <https://scipy.org>`_
* Cross-platform compatibility


Installation
------------

Cirq supports Python version 3.10 and later, and can be used on Linux, MacOS,
and Windows, as well as `Google Colab <https://colab.google/>`_. For complete
installation instructions, please refer to the `Install
<https://quantumai.google/cirq/start/install>`_ section of the Cirq
documentation.


“Hello Qubit” Example
---------------------

Here is a simple example to get you up and running with Cirq after you have
installed it. Start a Python interpreter, and then type the following:

.. code-block:: python

  import cirq

  # Pick a qubit.
  qubit = cirq.GridQubit(0, 0)

  # Create a circuit.
  circuit = cirq.Circuit(
      cirq.X(qubit)**0.5,  # Square root of NOT.
      cirq.measure(qubit, key='m')  # Measurement.
  )
  print("Circuit:")
  print(circuit)

  # Simulate the circuit several times.
  simulator = cirq.Simulator()
  result = simulator.run(circuit, repetitions=20)
  print("Results:")
  print(result)

You should see the following output printed by Python:

.. code-block::

  Circuit:
  (0, 0): ───X^0.5───M('m')───
  Results:
  m=11000111111011001000

Congratulations! You have run your first quantum simulation in Cirq. You can
continue learning more by exploring the `many Cirq tutorials
<#tutorials>`_ described below.


Cirq Documentation
------------------

Documentation for Cirq is available `quantumai.google/cirq
<https://quantumai.google/cirq>`_ as well as on Google Colab and YouTube.


Tutorials
.........

* The `video tutorials
  <https://www.youtube.com/playlist?list=PLpO2pyKisOjLVt_tDJ2K6ZTapZtHXPLB4>`_
  on YouTube are an engaging way to learn Cirq.

* The `Jupyter notebook-based tutorials
  <https://colab.research.google.com/github/quantumlib/Cirq>`_ in Google Colab
  let you learn and use Cirq right from your browser – no need to install
  anything on your computer.

* The traditional `text-based tutorials
  <https://quantumai.google/cirq/start/basics>`_ are best when combined with a
  local installation of Cirq on your computer.


Reference Documentation
.......................

* `Reference documentation
  <https://quantumai.google/reference/python/cirq/all_symbols>`_ for the
  latest **stable** version (what you get when you run
  ``pip install cirq``) is available on the Quantum AI website.

* Documentation for the latest **pre-release** version (the one that
  tracks the repository's main branch, which is what you get if you run
  ``pip install cirq~=1.5.dev``) is `available separately
  <https://quantumai.google/reference/python/cirq/all_symbols?version=nightly>`_.


Integrations
------------

* Once your circuits get larger, we recommend looking at `qsim
  <https://github.com/quantumlib/qsim>`_ and `Stim
  <https://github.com/quantumlib/stim>`_ – two efficient and powerful
  quantum circuit simulators.

* If you're interested in quantum algorithms research and fault-tolerant
  quantum computing, we recommend exploring `Qualtran
  <https://github.com/quantumlib/qualtran>`_ (the *quantum algorithms
  translator*), a Python library for expressing and analyzing fault-tolerant
  quantum algorithms.

* If you're interested in using quantum computers to solve problems in
  chemistry and materials science, we encourage exploring `OpenFermion
  <https://github.com/quantumlib/openfermion>`_ and `OpenFermion-Cirq
  <https://github.com/quantumlib/openfermion-cirq>`_, its sister library for
  compiling quantum simulation algorithms in Cirq.

* For machine learning enthusiasts, `Tensorflow Quantum
  <https://github.com/tensorflow/quantum>`_ is a great project to check out!

* Finally, `ReCirq <https://github.com/quantumlib/ReCirq>`_ contains
  real-world experiments using Cirq.


Community
---------

Cirq has benefited from open-source contributions by over 200 people and
counting. We are dedicated to cultivating an open and inclusive community to
build software for near-term quantum computers, and have a `code of conduct
<https://github.com/quantumlib/cirq/blob/main/CODE_OF_CONDUCT.md>`_ for our
community.

We use `GitHub issues <https://github.com/quantumlib/Cirq/issues>`_ to track
bug reports and feature requests. If you have a feature request or want to
report a bug, please `open an issue on GitHub
<https://github.com/quantumlib/Cirq/issues/new/choose>`_ to report it. We also
welcome code contributions to Cirq. Before opening your first `pull request
<https://help.github.com/articles/about-pull-requests/>`_, a good place to
start is to read our `contribution guidelines
<https://github.com/quantumlib/cirq/blob/main/CONTRIBUTING.md>`_.

.. |cirq| replace:: ``cirq``
.. _cirq: https://quantumcomputing.stackexchange.com/questions/tagged/cirq

For questions about how to use Cirq, you can post to `Quantum Computing Stack
Exchange <https://quantumcomputing.stackexchange.com/>`_ and tag your posting
with the |cirq|_ tag.
(Make sure to read the `guidelines for asking questions
<https://quantumcomputing.stackexchange.com/help/how-to-ask>`_ first, to
improve your chances of getting useful replies!)

**Cirq Cynq** is our biweekly meeting for contributors to discuss upcoming
features, designs, issues, community, and status of different efforts. It's
also a good place to ask questions about quantum computing and Cirq. To get an
invitation, please join the `cirq-dev
<https://groups.google.com/forum/#!forum/cirq-dev>`_ Google Group.

Finally, to be notified about new releases, sign up to the `cirq-announce
mailing list <https://groups.google.com/forum/#!forum/cirq-announce>`__!


Citing Cirq
-----------

Each Cirq release is uploaded to Zenodo automatically. When publishing or
referring to Cirq, please cite the Cirq release you're using. Click on the
badge below to visit the Cirq releases page on Zenodo, then look for the
*Citation* box along the right-hand side of the page:

.. raw:: html

   <div align="center">

|Zenodo|

.. raw:: html

   </div>

Contact
-------

For any questions or concerns not addressed here, please email
quantum-oss-maintainers@google.com.

Cirq is not an official Google product. Copyright 2019 The Cirq Developers

.. raw:: html

   <div align="center">

.. image:: https://avatars.githubusercontent.com/u/31279789?s=200&v=4
   :target: https://quantumai.google
   :align: center
   :width: 100px
   :alt: Google Quantum AI

.. raw:: html

   </div>
