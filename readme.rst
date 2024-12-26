.. |license| image:: https://img.shields.io/badge/License-Apache%202.0-3c60b1.svg?logo=opensourceinitiative&logoColor=white&style=flat-square
   :alt: Licensed under the Apache 2.0 license
   :target: https://github.com/quantumlib/Cirq/blob/main/LICENSE

.. |python| image:: https://img.shields.io/badge/Python-3.10+-fcbc2c.svg?style=flat-square&logo=python&logoColor=white
   :alt: Compatible with Python versions 3.10 and higher
   :target: https://www.python.org/downloads/

.. |contributors| image:: https://img.shields.io/github/contributors/quantumlib/cirq?label=Contributors&logo=github&style=flat-square&color=lightgray
   :alt: GitHub contributors
   :target: https://github.com/quantumlib/Cirq/graphs/contributors

.. |stars| image:: https://img.shields.io/github/stars/quantumlib/cirq?style=flat-square&logo=github&label=Stars&color=lightgray
   :alt: GitHub stars
   :target: https://github.com/quantumlib/cirq

.. |zenodo| image:: https://img.shields.io/badge/10.5281%2Fzenodo.4062499-gray.svg?label=DOI&style=flat-square&colorA=gray&colorB=3c60b1
   :alt: Archived in Zenodo
   :target: https://doi.org/10.5281/zenodo.4062499

.. |ci| image:: https://img.shields.io/github/actions/workflow/status/quantumlib/cirq/ci.yml?event=schedule&style=flat-square&logo=GitHub&label=CI
   :alt: Cirq continuous integration status
   :target: https://github.com/quantumlib/Cirq/actions/workflows/ci-daily.yml

.. |codecov| image:: https://img.shields.io/codecov/c/github/quantumlib/cirq?style=flat-square&logo=codecov&logoColor=white&label=Codecov
   :alt: Code coverage report
   :target: https://codecov.io/gh/quantumlib/Cirq

.. |pypi| image:: https://img.shields.io/pypi/v/cirq.svg?logo=python&logoColor=white&label=PyPI&style=flat-square&color=fcbc2c
   :alt: Cirq project on PyPI
   :target: https://pypi.org/project/cirq

.. |colab| image:: https://img.shields.io/badge/Google%20Colab-gray.svg?style=flat-square&logo=googlecolab&logoColor=fd6c0c
   :alt: Google Colab
   :target: https://colab.google/


.. ▶︎─── start github-only
.. PyPI supports RST's ".. class::", but GitHub does not. PyPI respects
.. ":align:" for images, but GitHub does not. The only way to center text or
.. images in GitHub is to use raw HTML, which PyPI does not support (!!!).
.. To satisfy both, this file contains fences around code that is removed
.. when creating distributions for PyPI.

.. raw:: html

   <div align="center">
.. ▶︎─── end github-only

.. image:: https://raw.githubusercontent.com/quantumlib/Cirq/refs/heads/main/docs/images/Cirq_logo_color.svg
   :alt: Cirq logo
   :width: 280px
   :height: 135px
   :align: center

.. class:: centered

Python package for writing, manipulating, and running
`quantum circuits <https://en.wikipedia.org/wiki/Quantum_circuit>`__
on quantum computers and simulators.

.. class:: margin-top
.. class:: centered

| |license| |python| |colab| |pypi| |zenodo|
| |contributors| |stars| |ci| |codecov|

.. class:: centered

.. ▶︎─── start github-only
.. Note #1: the following addition of <p> is deliberate; it improves spacing.
.. Note #2: we're not done with the <div> -- it gets closed later, not here.
.. raw:: html

   <p>
.. ▶︎─── end github-only

`Features <#features>`__ •
`Installation <#installation>`__ •
`“Hello Qubit” <#hello-qubit-example>`__ •
`Documentation <#cirq-documentation>`__ •
`Integrations <#integrations>`__ •
`Community <#community>`__ •
`Citing Cirq <#citing-cirq>`__ •
`Contact <#contact>`__

.. ▶︎─── start github-only
.. raw:: html

   </p></div>
.. ▶︎─── end github-only


Features
--------

.. ▶︎─── start github-only
.. raw:: html

   <img align="right" width="200px" alt="Google's quantum computer"
        src="https://quantumai.google/static/site-assets/images/marketing/quantum-computing/hero-heading-mobile.jpg"/>
.. ▶︎─── end github-only

Cirq provides useful abstractions for dealing with today’s `noisy
intermediate-scale quantum <https://arxiv.org/abs/1801.00862>`__ (NISQ)
computers, where the details of quantum hardware are vital to achieving
state-of-the-art results. Some of its features include:

* Flexible gate definitions and custom gates
* Parametrized circuits with symbolic variables
* Circuit transformation, compilation and optimization
* Hardware device modeling
* Noise modeling
* Multiple built-in quantum circuit simulators
* Integration with `qsim <https://github.com/quantumlib/qsim>`__ for
  high-performance simulation
* Interoperability with `NumPy <https://numpy.org>`__ and
  `SciPy <https://scipy.org>`__
* Cross-platform compatibility


Installation
------------

Cirq supports Python version 3.10 and later, and can be used on Linux, MacOS,
and Windows, as well as `Google Colab <https://colab.google/>`__. For complete
installation instructions, please refer to the `Install
<https://quantumai.google/cirq/start/install>`__ section of the Cirq
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

.. code-block:: text

  Circuit:
  (0, 0): ───X^0.5───M('m')───
  Results:
  m=11000111111011001000

Congratulations! You have run your first quantum simulation in Cirq. You can
continue learning more by exploring the `many Cirq tutorials
<#tutorials>`__ described below.


Cirq Documentation
------------------

Tutorials
.........

* `Video tutorials
  <https://www.youtube.com/playlist?list=PLpO2pyKisOjLVt_tDJ2K6ZTapZtHXPLB4>`__
  on YouTube are an engaging way to learn Cirq.

* `Jupyter notebook-based tutorials
  <https://colab.research.google.com/github/quantumlib/Cirq>`__ let you learn
  Cirq from your browser – no installation needed.

* `Text-based tutorials <https://quantumai.google/cirq/start/basics>`__ are
  great when combined with a local installation of Cirq on your computer.


Reference Documentation
.......................

* Docs for the `current stable release
  <https://quantumai.google/reference/python/cirq/all_symbols>`__ correspond
  to what you get with ``pip install cirq``.

* Docs for the `pre-release
  <https://quantumai.google/reference/python/cirq/all_symbols?version=nightly>`__
  correspond to what you get with ``pip install cirq~=1.5.dev``.


Change log
..........

* The `Cirq releases <https://github.com/quantumlib/cirq/releases>`__ page on
  GitHub lists the changes in each release.


Integrations
------------

Google Quantum AI has a suite of open-source software thats let you do more
with Cirq. From high-performance simulators, to novel tools for expressing and
analyzing fault-tolerant quantum algorithms, our software stack lets you
develop quantum programs for a variety of applications.

.. |qsim| replace:: qsim
.. _qsim: https://github.com/quantumlib/qsim

.. |stim| replace:: Stim
.. _stim: https://github.com/quantumlib/stim

.. |qualtran| replace:: Qualtran
.. _qualtran: https://github.com/quantumlib/qualtran

.. |openfermion| replace:: OpenFermion
.. _openfermion: https://github.com/quantumlib/openfermion

.. |openfermioncirq| replace:: OpenFermion-Cirq
.. _openfermioncirq: https://github.com/quantumlib/openfermion_cirq

.. |recirq| replace:: ReCirq
.. _recirq: https://github.com/quantumlib/recirq

.. |tfq| replace:: TensorFlow Quantum
.. _tfq: https://github.com/tensorflow/quantum


.. ▶︎─── start github-only
.. raw:: html

   <div align="center">
.. ▶︎─── end github-only
.. class:: centered

+-------------------------------------------------------+---------------------+
| Your interests                                        | Software to explore |
+=======================================================+=====================+
| Large circuits and/or a lot of simulations?           | * |qsim|_           |
|                                                       | * |stim|_           |
+-------------------------------------------------------+---------------------+
| Quantum algorithms?                                   | * |qualtran|_       |
| Fault-tolerant quantum computing (FTQC)?              |                     |
+-------------------------------------------------------+---------------------+
| Quantum error correction (QEC)?                       | * |stim|_           |
+-------------------------------------------------------+---------------------+
| Chemistry and/or material science?                    | * |openfermion|_    |
|                                                       | * |openfermioncirq|_|
+-------------------------------------------------------+---------------------+
| Quantum machine-learning (QML)?                       | * |tfq|_            |
+-------------------------------------------------------+---------------------+
| Real experiments using Cirq?                          | * |recirq|_         |
+-------------------------------------------------------+---------------------+

.. ▶︎─── start github-only
.. raw:: html

   </div>
.. ▶︎─── end github-only


Community
---------

Cirq has benefited from open-source contributions by over 200 people and
counting. We are dedicated to cultivating an open and inclusive community to
build software for quantum computers, and have a `code of conduct
<https://github.com/quantumlib/cirq/blob/main/CODE_OF_CONDUCT.md>`__ for our
community.


Announcements
.............

Stay on top of Cirq developments using the approach that best suits your needs:

* Cirq releases and major announcements: sign up to the low-volume mailing list
  `cirq-announce <https://groups.google.com/forum/#!forum/cirq-announce>`__.
* Cirq releases only:
    * Via GitHub notifications: configure `GitHub repository notifications
      <https://docs.github.com/en/account-and-profile/managing-subscriptions-and-notifications-on-github/setting-up-notifications/configuring-notifications#configuring-your-watch-settings-for-an-individual-repository>`__
      for the Cirq repo.
    * Via Atom/RSS from GitHub: subscribe to the `Cirq releases Atom feed
      <https://github.com/quantumlib/Cirq/releases.atom>`__.
    * Via RSS from PyPI: subscribe to the `Cirq releases RSS feed
      <https://pypi.org/rss/project/cirq/releases.xml>`__.


Questions and Discussions
.........................

.. |cirq| replace:: ``cirq``
.. _cirq: https://quantumcomputing.stackexchange.com/questions/tagged/cirq

* Do you have questions about using Cirq? Post them to the `Quantum Computing
  Stack Exchange <https://quantumcomputing.stackexchange.com/>`__ and tag them
  with the |cirq|_ tag.

* Would you like to get more involved? *Cirq Cynq* is our biweekly virtual
  meeting of contributors to discuss everything from issues to ongoing
  efforts, as well as to ask questions. Join the `cirq-dev
  <https://groups.google.com/forum/#!forum/cirq-dev>`__ Google Group to get a
  meeting invitation.


Issues and Pull Requests
........................

* Do you have a feature request or want to report a bug? `Open an issue on
  GitHub <https://github.com/quantumlib/Cirq/issues/new/choose>`__ to report it!

* Do you have a code contribution? Read our `contribution guidelines
  <https://github.com/quantumlib/cirq/blob/main/CONTRIBUTING.md>`__, then open
  a `pull request <https://help.github.com/articles/about-pull-requests/>`__!


Citing Cirq
-----------

When publishing articles or otherwise writing about Cirq, please cite the Cirq
version you use – it will help others reproduce your results. We use Zenodo to
preserve releases. The following links let you download the bibliographic
record for the latest stable release of Cirq in various popular formats:

.. |bibtex| image:: https://img.shields.io/badge/Download%20record-eeeeee.svg?style=flat-square&logo=LaTeX&label=BibTeX&labelColor=106f6e
   :alt: Download BibTeX bibliography record for latest Cirq release
   :target: https://zenodo.org/records/8161252/export/bibtex

.. |marcxml| image:: https://img.shields.io/badge/Download%20record-eeeeee.svg?style=flat-square&label=MARCXML&labelColor=2600c1&logo=data:image/gif;base64,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
   :alt: Download MARCXML bibliography record for latest Cirq release
   :target: https://zenodo.org/records/8161252/export/marcxml

.. |csl| image:: https://img.shields.io/badge/Download%20record-eeeeee.svg?style=flat-square&label=CSL&labelColor=2d98e0&logo=data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAACAAAAAUCAMAAADbT899AAAACXBIWXMAAAnXAAAJ1wGxbhe3AAABGlBMVEUtmOBZreZhsuhSquVNp+RfsOcsmOD///92vOs3neHx+P2n1PLY7PrS6fmi0vE7nuJ8v+z+//9Tq+VJpuT8/v+Fw+3t9/2r1vPH4/fd7vovmeCf0PH0+v5uuOlesOfV6/nO5/ik0vLy+f41nOFbr+fL5vhVq+Y6nuLI5Pd6vutotelntOg/oOL2+/6YzfDb7vrQ6Pim1PLw+P04neHK5fcumOCUy+/4/P5CouNst+k7n+Lz+f6e0PFQqeX9/v9+wOwzm+Ht9v2w2PPB4fbg8PuPyO/7/f9HpeSt1/NLp+SDwu3p9fy33PV5vetVrOZSq+av2POczvA+oOJ1u+tFpOOMx+7q9fyy2fS+3/bi8fsxmuCWzPBBouNaruaHgOQWAAAAXnRSTlP////////+///////////////////////////////////////////////////////////////////////////////////////////////+/v//////////////////3JzDywAAAQRJREFUeJyNkddWwkAURS9VgyBFDYIFdewNlAQrVcVewQr+/2+Yc3gylwfuy5619pk5mYnIKBMIehOSMBD5r6L0Y5hxKwZMDAnEIRIyCcSSuiAFkc5MTYMz2ls2RFZmgVzeZ72KOYj55AI/ZNG/3QsUIJZkGVgxq2uY9Y1NYIuBbW7d2d0D9qUIlOQAOCzzFAfrolsBjo6DzJ+cngHnvGa1hnW90QRacgFc5q+A9jXf4QbrpuF1a9VbXveucQ88sGNQX3FZ70iW9eaRXU9D/gwDtjUIPGufSUOkDN/vJaoDCYi4vPL93rTv8ORAtw28a28+ID7lC/j+EVUR6mH6FvErOqDmD0UfH1PhwykNAAAAAElFTkSuQmCC
   :alt: Download CSL JSON bibliography record for latest Cirq release
   :target: https://zenodo.org/records/8161252/export/csl

.. ▶︎─── start github-only
.. raw:: html

   <div align="center">
   <p>
.. ▶︎─── end github-only
.. class:: centered

|bibtex|    |marcxml|    |csl|

.. ▶︎─── start github-only
.. raw:: html

   </p>
   </div>
.. ▶︎─── end github-only

For formatted citations and records in other formats, as well as records for
all releases of Cirq past and present, visit the `Cirq page on Zenodo
<https://doi.org/10.5281/zenodo.4062499>`__.


Contact
-------

For any questions or concerns not addressed here, please email
quantum-oss-maintainers@google.com.


Disclaimer
----------

Cirq is not an official Google product. Copyright 2019 The Cirq Developers
