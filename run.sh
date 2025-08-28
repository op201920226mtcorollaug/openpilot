#!/bin/bash
set -e

# Configuration
OP_REPO="https://github.com/commaai/openpilot.git"
OP_BRANCH="nightly-dev"
OP_DIR="tmp/openpilot"
OP_PATCH_BRANCH="op-nightly-dev"

SP_REPO="https://github.com/sunnypilot/sunnypilot.git"
SP_BRANCH="staging-c3-new"
SP_DIR="tmp/sunnypilot"
SP_PATCH_BRANCH="sp-staging-c3-new"

# Clean up previous run
rm -rf tmp
mkdir -p tmp

# Clone Repositories
echo "Cloning repositories..."
git clone --depth=1 --branch="$OP_BRANCH" "$OP_REPO" "$OP_DIR"
git -C "$OP_DIR" fsck
git clone --depth=1 --branch="$SP_BRANCH" "$SP_REPO" "$SP_DIR"
git -C "$SP_DIR" fsck

# Apply Patches
echo "Applying patches..."
git -C "$OP_DIR" apply ../../patches/openpilot.patch
echo "Patched openpilot."

# For sunnypilot, we apply the same patches
git -C "$SP_DIR" apply ../../patches/sunnypilot.patch
echo "Patched sunnypilot."


# Commit and Push Changes
echo "Committing and pushing changes..."

# openpilot
cd "$OP_DIR"
git config user.name "Automated Bot"
git config user.email "actions@github.com"
git remote set-url origin "https://x-access-token:${GITHUB_TOKEN}@github.com/${GITHUB_REPOSITORY:-op6mtcorollaug/openpilot}.git"
git add .
GIT_AUTHOR_DATE='2021-08-08 00:00:00 +0000' GIT_COMMITTER_DATE='2021-08-08 00:00:00 +0000' git commit -m "Apply 6MT TSS2 Corolla patches"
git push origin "HEAD:$OP_PATCH_BRANCH" --force
cd -

# sunnypilot
cd "$SP_DIR"
git config user.name "Automated Bot"
git config user.email "actions@github.com"
git remote set-url origin "https://x-access-token:${GITHUB_TOKEN}@github.com/${GITHUB_REPOSITORY:-op6mtcorollaug/openpilot}.git"
git add .
GIT_AUTHOR_DATE='2021-08-08 00:00:00 +0000' GIT_COMMITTER_DATE='2021-08-08 00:00:00 +0000' git commit -m "Apply 6MT TSS2 Corolla patches"
git push origin "HEAD:$SP_PATCH_BRANCH" --force
cd -

echo "Script finished."