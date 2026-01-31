# Sync Script Patch Fix Explanation

## Problem

The sync script (`run.sh`) was failing with the following error:

```
error: patch failed: opendbc_repo/opendbc/car/toyota/carstate.py:163
error: opendbc_repo/opendbc/car/toyota/carstate.py: patch does not apply
```

## Root Cause

The upstream repositories (commaai/openpilot and sunnypilot/sunnypilot) have evolved since the patches were originally created. This caused the patch files to reference incorrect line numbers and outdated code context.

### Specific Changes in Upstream

1. **openpilot repository (nightly-dev branch)**:
   - The target line moved from line 163 to **line 160**
   - The code context changed: `self.pcm_acc_status` was refactored to a local variable `pcm_acc_status`
   - The `launch_env.sh` file structure changed with different line numbering

2. **sunnypilot repositories (all branches)**:
   - The target line moved from line 163 to **line 164**
   - The code context remains the same (still uses `self.pcm_acc_status`)
   - The `launch_env.sh` file has a different structure than openpilot

## Solution

Updated both patch files to reflect the current state of the upstream repositories:

### openpilot.patch Changes

**Before:**
```diff
@@ -163,7 +163,7 @@
     if (self.CP.carFingerprint not in TSS2_CAR and self.CP.carFingerprint not in UNSUPPORTED_DSU_CAR) or \
        (self.CP.carFingerprint in TSS2_CAR and self.acc_type == 1):
       if self.CP.openpilotLongitudinalControl:
-        ret.accFaulted = ret.accFaulted or cp.vl["PCM_CRUISE_2"]["LOW_SPEED_LOCKOUT"] == 2
+        ret.accFaulted = ret.accFaulted or False

     self.pcm_acc_status = cp.vl["PCM_CRUISE"]["CRUISE_STATE"]
     if self.CP.carFingerprint not in (NO_STOP_TIMER_CAR - TSS2_CAR):
```

**After:**
```diff
@@ -160,7 +160,7 @@
     if (self.CP.carFingerprint not in TSS2_CAR and self.CP.carFingerprint not in UNSUPPORTED_DSU_CAR) or \
        (self.CP.carFingerprint in TSS2_CAR and self.acc_type == 1):
       if self.CP.openpilotLongitudinalControl:
-        ret.accFaulted = ret.accFaulted or cp.vl["PCM_CRUISE_2"]["LOW_SPEED_LOCKOUT"] == 2
+        ret.accFaulted = ret.accFaulted or False

     pcm_acc_status = cp.vl["PCM_CRUISE"]["CRUISE_STATE"]
     ret.cruiseState.standstill = pcm_acc_status == 7
```

Key changes:
- Line number: `163` → `160`
- Context line: `self.pcm_acc_status` → `pcm_acc_status`
- Updated to match the refactored code structure

**launch_env.sh patch:**
```diff
@@ -22,3 +22,4 @@
 fi

 export STAGING_ROOT="/data/safe_staging"
+export FINGERPRINT="TOYOTA_COROLLA_TSS2"
```
- Updated line reference from `@@ -11,3 +11,4 @@` to `@@ -22,3 +22,4 @@`

### sunnypilot.patch Changes

**Before:**
```diff
@@ -163,7 +163,7 @@
```

**After:**
```diff
@@ -164,7 +164,7 @@
```

Key changes:
- Line number: `163` → `164`
- Context remains the same (still uses `self.pcm_acc_status`)

**launch_env.sh patch:**
```diff
@@ -13,3 +13,4 @@
 fi

 export STAGING_ROOT="/data/safe_staging"
+export FINGERPRINT="TOYOTA_COROLLA_TSS2"
```
- Updated line reference from `@@ -11,3 +11,4 @@` to `@@ -13,3 +13,4 @@`

## Verification

After applying these changes, the sync script runs successfully:

```bash
$ ./run.sh
Cloning repositories...
...
Applying patches...
Patched openpilot.
Patched sunnypilot C3X staging.
Patched sunnypilot C3 staging.
Patched sunnypilot C3X release.
Patched sunnypilot C3X dev.
Committing and pushing changes...
...
```

All five repositories are now patched successfully without errors.

## Why Patches Break

Git patches are context-sensitive and include:
1. **Line numbers** - The starting line of the change
2. **Context lines** - Lines before and after the change to ensure correct matching
3. **Content** - The actual lines being changed

When upstream code changes through:
- Code refactoring
- Line additions/deletions elsewhere in the file
- Variable name changes
- Code restructuring

The patches need to be updated to match the new context and line numbers.

## Maintenance

To keep patches working in the future:
1. Regularly test the sync script
2. When patches fail, compare the patch file with the actual upstream code
3. Update line numbers and context to match current upstream state
4. Consider using more robust patching strategies if frequent updates are needed
