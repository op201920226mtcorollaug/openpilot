# openpilot and forks for 2019-2022 6MT manual transmission TSS2 Corollas

![Shifter](https://github.com/user-attachments/assets/a7f471e8-0e70-4f9c-aac2-6d69815745ab)

[Image from Hooniverse](https://www.hooniverse.com/2020-toyota-corolla-is-all-about-savethemanuals-but-will-you-buy-it/)

This is an automated repository that patches comma.ai openpilot's `nightly-dev` and sunnypilot's `staging-c3-new` branches to support 2019-2022 6MT manual transmission TSS2 Corollas.

Efforts to upstream support for the 2019-2022 6MT manual transmission TSS2 Corollas have stalled with a principal developer of the 2019-2022 Corolla 6MT manual transmission TSS2 support unable to [contribute additional time for upstreaming](https://discord.com/channels/469524606043160576/1391211035796439163/1391232320790331472) (join the comma Discord).

Discussion about this repository can be found in the [comma.ai openpilot Discord](https://discord.comma.ai) in the [2019-2022 6MT Corolla Thread underneath #toyota-lexus](https://discord.com/channels/469524606043160576/1391211035796439163). **Note: You must first join the comma Discord using the invitation link above before you can access the specific Discord channel links.** If you have questions, please ask there, but not before reading this documentation, of course!

## How this repository Works

[A GitHub Actions workflow](https://github.com/op201920226mtcorollaug/openpilot/actions) runs on a daily schedule to:

1.  Clone the latest versions of openpilot and sunnypilot.
2.  Apply the necessary patches from the `/patches` directory.
    * Force the vehicle to be identified as a 2019-2022 TSS2 Corolla.
    * Modify the openpilot's car state tracker to accept the 2019-2022 6MT manual transmission TSS2 Corolla's speed lockout.
3.  Force-push the patched codebases to the `op-nightly-dev` and `sp-staging-c3-new` branches in this repository.

## Usage

Users will install a patched version of openpilot or sunnypilot on your comma three family device from this repository.

1. Reset the comma three device. You can do this by tapping on the screen during bootup, uninstalling the software from the Settings menu, or using https://flash.comma.ai.
2. Choose `Custom Software` when installing the software.
3. In the text field, enter the following:
   * sunnypilot - _The community of 2019-2022 6MT TSS2 Corolla users recommend this for users with MADS pre-enabled_
     * `op201920226mtcorollaug/sp-staging-c3-new`
   * comma.ai openpilot - _Patched version of comma's software, kept around more for upstreaming preview and testing than actual usage_
     * `op201920226mtcorollaug/op-nightly-dev`
     * If you have comma hardware issues, it's possible that comma might be lenient with you if you use this for support, but it's really not guaranteed. It's best to switch the device to using comma's unpatched codebase in dashcam mode if you have hardware issues for support.
5. That's it, you're done! The device will install the patched version of openpilot or sunnypilot.
6. This repository will automatically pull down and patch from upstream software and push to itself so you will get prompted to reboot for updates once in a while.

## Expected Behavior

* There is no stop and go in 6MT TSS2 Corollas.
* OP activates: In gears > 1st, and at > ~18mph. Below that, everything disengages (unless using sunnypilot, only ACC disengages).
* See this video for how it behaves in comma openpilot: https://youtu.be/ITxknEpp9R8
* Sunnypilot with MADS behaves differently.
  * WITHOUT MADS (like in comma openpilot): You can’t engage anything under 18 mph and whenever you engage it over 18 mph, you are also engaging adaptive cruise control
  * WITH MADS (default out of box in sunnypilot): In slower traffic you can still keep the steering assist enabled so you just have to control speed/shifting gears

### Later Usage

* This repository can and might break. Please discuss the issue in the thread linked above.
* This repository may become obsolete as upstream support may be added to openpilot or sunnypilot. Please check the thread linked above for updates.
* Last but not least, if you got the skills to help upstream support for this Corolla, please seriously considering picking up where [bscholer left off](https://github.com/commaai/openpilot/pull/26872) with the changes in this repo also as guidance. As it stands, you cannot get comma to support hardware issues with your comma device with these changes.
