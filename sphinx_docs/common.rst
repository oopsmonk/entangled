IOTA Common Libraries
======================

The common libraries are including Crypto, Helpers, Models, and Trinary components.

Common
--------

.. doxygentypedef:: retcode_t
   :project: Entangled


Error codes, see `error.h`_

.. doxygenfunction:: error_2_string
   :project: Entangled

.. _error.h: https://github.com/oopsmonk/entangled/blob/develop/common/errors.h


Crypto
--------

**TODO**

Helpers
--------

**TODO**


Models
--------

.. doxygenfile:: common/model/bundle.h
   :project: Entangled

.. doxygenfile:: common/model/inputs.h
   :project: Entangled


Trinary
--------

.. doxygentypedef:: flex_trit_t
   :project: Entangled

.. doxygenfunction:: flex_trits_at
   :project: Entangled

.. doxygenfunction:: flex_trits_set_at
   :project: Entangled

.. doxygenfunction:: flex_trits_are_null
   :project: Entangled

.. doxygenfunction:: flex_trits_slice
   :project: Entangled

.. doxygenfunction:: flex_trits_insert
   :project: Entangled

.. doxygenfunction:: flex_trits_to_trits 
   :project: Entangled

.. doxygenfunction:: flex_trits_from_trits 
   :project: Entangled

.. doxygenfunction:: flex_trits_from_trytes
   :project: Entangled

.. doxygenfunction:: flex_trits_to_bytes
   :project: Entangled

.. doxygenfunction:: flex_trits_from_bytes
   :project: Entangled

.. doxygenfunction:: flex_trit_print 
   :project: Entangled
