var group__group__hal__impl__hw__types =
[
    [ "cyhal_clock_t", "group__group__hal__impl__hw__types.html#structcyhal__clock__t", [
      [ "block", "group__group__hal__impl__hw__types.html#a60762f348f4de6260d4eee35a6cd6560", null ],
      [ "channel", "group__group__hal__impl__hw__types.html#aa27063ada31404de933c54ade97205df", null ],
      [ "reserved", "group__group__hal__impl__hw__types.html#a4b783c0785fab0565508506aeb055429", null ],
      [ "funcs", "group__group__hal__impl__hw__types.html#aaf4cdeb909d79bfa101c6f372d25ed95", null ]
    ] ],
    [ "cyhal_resource_inst_t", "group__group__hal__impl__hw__types.html#structcyhal__resource__inst__t", [
      [ "type", "group__group__hal__impl__hw__types.html#ad111187a65d182386ea96858369b83d4", null ],
      [ "block_num", "group__group__hal__impl__hw__types.html#a91895766b5f5efe1dfffac2d7537e73a", null ],
      [ "channel_num", "group__group__hal__impl__hw__types.html#a4488a199114a86e5a72184c7a0a16c06", null ]
    ] ],
    [ "cyhal_event_callback_data_t", "group__group__hal__impl__hw__types.html#structcyhal__event__callback__data__t", [
      [ "callback", "group__group__hal__impl__hw__types.html#a3c3d10edf78afaf402eb6eb9004a17c0", null ],
      [ "callback_arg", "group__group__hal__impl__hw__types.html#aeabdbaef4f75c5b947fa9d1534d230f9", null ]
    ] ],
    [ "cyhal_tcpwm_t", "group__group__hal__impl__hw__types.html#structcyhal__tcpwm__t", [
      [ "owned_by_configurator", "group__group__hal__impl__hw__types.html#a3df8368126bee60d27fdf661a739629c", null ],
      [ "base", "group__group__hal__impl__hw__types.html#afcbafe1118309449887b2d1e71589be8", null ],
      [ "resource", "group__group__hal__impl__hw__types.html#a8ccce14a59d1387736d5e28469a43af1", null ],
      [ "clock", "group__group__hal__impl__hw__types.html#a4c8ba4a2754b8447ce97969933baff39", null ],
      [ "dedicated_clock", "group__group__hal__impl__hw__types.html#a21f9fdb1ebd75cc3a229e6b8359d7277", null ],
      [ "clock_hz", "group__group__hal__impl__hw__types.html#a61e96b14af811d1664fdee09caad9f12", null ],
      [ "callback_data", "group__group__hal__impl__hw__types.html#a4ca7850ec02d62ce98b20273a040cab0", null ]
    ] ],
    [ "cyhal_dma_t", "group__group__hal__impl__hw__types.html#structcyhal__dma__t", [
      [ "resource", "group__group__hal__impl__hw__types.html#a435949478e9279c9270c62843a69070e", null ],
      [ "channel_config", "group__group__hal__impl__hw__types.html#ab95c46736c4721480ddc4dded574b8f3", null ],
      [ "descriptor_config", "group__group__hal__impl__hw__types.html#a47827b4c0b730eb66f36ac7916d459db", null ],
      [ "descriptor", "group__group__hal__impl__hw__types.html#a863c863640536cf57231ce5819fd4707", null ],
      [ "expected_bursts", "group__group__hal__impl__hw__types.html#ada48a4096fb83a7e69cd10f079c250bb", null ],
      [ "direction", "group__group__hal__impl__hw__types.html#a6bfa3d9c7ef3bb07d45f1022bab70c87", null ],
      [ "irq_cause", "group__group__hal__impl__hw__types.html#ae05f049b8e40d8f1a111ec3328afc5a7", null ],
      [ "callback_data", "group__group__hal__impl__hw__types.html#a9fb6d3fe2403deb665ce86e958fb956a", null ],
      [ "source", "group__group__hal__impl__hw__types.html#a5e5aa9c3349f413a5e685a6e08bb9538", null ],
      [ "owned_by_configurator", "group__group__hal__impl__hw__types.html#a881b87e28aa62a3a0702f397e07bae42", null ]
    ] ],
    [ "cyhal_dma_t.channel_config", "group__group__hal__impl__hw__types.html#unioncyhal__dma__t_8channel__config", [
      [ "dw", "group__group__hal__impl__hw__types.html#a1f2121f36f817bd18540e5fa7de06f59", null ],
      [ "dmac", "group__group__hal__impl__hw__types.html#ae555fc29296b95adb45c0092d8f35338", null ]
    ] ],
    [ "cyhal_dma_t.descriptor_config", "group__group__hal__impl__hw__types.html#unioncyhal__dma__t_8descriptor__config", [
      [ "dw", "group__group__hal__impl__hw__types.html#a1f2121f36f817bd18540e5fa7de06f59", null ],
      [ "dmac", "group__group__hal__impl__hw__types.html#ae555fc29296b95adb45c0092d8f35338", null ]
    ] ],
    [ "cyhal_dma_t.descriptor", "group__group__hal__impl__hw__types.html#unioncyhal__dma__t_8descriptor", [
      [ "dw", "group__group__hal__impl__hw__types.html#a1f2121f36f817bd18540e5fa7de06f59", null ],
      [ "dmac", "group__group__hal__impl__hw__types.html#ae555fc29296b95adb45c0092d8f35338", null ]
    ] ],
    [ "cyhal_dma_configurator_t", "group__group__hal__impl__hw__types.html#structcyhal__dma__configurator__t", [
      [ "empty", "group__group__hal__impl__hw__types.html#a8aa524d0280952d875d7160526ef2902", null ]
    ] ],
    [ "_cyhal_audioss_interface_t", "struct__cyhal__audioss__interface__t.html", [
      [ "invoke_user_callback", "struct__cyhal__audioss__interface__t.html#ae21faa347539cbf2969539748d346e64", null ],
      [ "event_mask_empty", "struct__cyhal__audioss__interface__t.html#a25b71f7a381aa9e56f0ecf5fc1fe9e89", null ],
      [ "event_mask_half_empty", "struct__cyhal__audioss__interface__t.html#ac9e41dd6253b3f8de07634e49e891f44", null ],
      [ "event_mask_full", "struct__cyhal__audioss__interface__t.html#ac678187b982a338f7881f6c08d313c7c", null ],
      [ "event_mask_half_full", "struct__cyhal__audioss__interface__t.html#a86f8875bf98bf422e046a85bd9a72240", null ],
      [ "event_rx_complete", "struct__cyhal__audioss__interface__t.html#a48cf21d9a99302dbeb3e479866caae3a", null ],
      [ "event_tx_complete", "struct__cyhal__audioss__interface__t.html#aa5d98affaae5cf6475ccf5d5ac7588c6", null ],
      [ "err_invalid_pin", "struct__cyhal__audioss__interface__t.html#ae494185e0ccae1a2e238c7025764bbf9", null ],
      [ "err_invalid_arg", "struct__cyhal__audioss__interface__t.html#a165f5d2699fa7454c60ff05255439027", null ],
      [ "err_clock", "struct__cyhal__audioss__interface__t.html#a3f83605d15a9fc3b51a97693074ce041", null ],
      [ "err_not_supported", "struct__cyhal__audioss__interface__t.html#a71534ffd0564650b16f451961a704544", null ]
    ] ],
    [ "_cyhal_audioss_t", "group__group__hal__impl__hw__types.html#struct__cyhal__audioss__t", [
      [ "empty", "group__group__hal__impl__hw__types.html#a31b0deb4b681c9978a07c36ce594c395", null ]
    ] ],
    [ "_cyhal_audioss_configurator_t", "group__group__hal__impl__hw__types.html#struct__cyhal__audioss__configurator__t", [
      [ "resource", "group__group__hal__impl__hw__types.html#adf0c4b328c9124608f7fe34c5d02898a", null ],
      [ "clock", "group__group__hal__impl__hw__types.html#ac469ce88f06b12e1b5763c59806def6f", null ],
      [ "mclk_hz_rx", "group__group__hal__impl__hw__types.html#afbfc4446a510fea35381042381b87f23", null ],
      [ "mclk_hz_tx", "group__group__hal__impl__hw__types.html#ae1dab79abba865a3ddd7d876f8ae00b1", null ]
    ] ],
    [ "cyhal_adc_t", "group__group__hal__impl__hw__types.html#structcyhal__adc__t", [
      [ "owned_by_configurator", "group__group__hal__impl__hw__types.html#a67e97e86d51bd44eafba139d98150318", null ],
      [ "base", "group__group__hal__impl__hw__types.html#ac5615cdba01efd5c110f0ca6adbef43e", null ],
      [ "channel_config", "group__group__hal__impl__hw__types.html#a80387c168decb163670d999d25ab9861", null ],
      [ "resource", "group__group__hal__impl__hw__types.html#a9343981a568de936a5c729c9b94e3888", null ],
      [ "clock", "group__group__hal__impl__hw__types.html#aa7f9c40ac381cf1ba12d887a498938b0", null ],
      [ "dedicated_clock", "group__group__hal__impl__hw__types.html#a1446fcf0c070b58ba0a02a6d1ad0e167", null ],
      [ "conversion_complete", "group__group__hal__impl__hw__types.html#aee91178fbd81ee50efb413d028ae3519", null ],
      [ "stop_after_scan", "group__group__hal__impl__hw__types.html#adf8fd7f1cde5ed931d5fdebf5b8928c6", null ],
      [ "user_enabled_events", "group__group__hal__impl__hw__types.html#a6ae0542a24823c0931f95eb71cc6db33", null ],
      [ "callback_data", "group__group__hal__impl__hw__types.html#a215032cbf5b0e332de57edc6e08b967b", null ],
      [ "async_buff_next", "group__group__hal__impl__hw__types.html#a1183a11bed557a6643c10de4a2cde754", null ],
      [ "async_transfer_in_uv", "group__group__hal__impl__hw__types.html#a762f879937906d9d3ea371de58faa1e6", null ],
      [ "async_scans_remaining", "group__group__hal__impl__hw__types.html#a1460a01df6bff30e507cd971dd8b908d", null ],
      [ "continuous_scanning", "group__group__hal__impl__hw__types.html#a503d77d3c3fe26ec55140a57dcf67b69", null ],
      [ "async_mode", "group__group__hal__impl__hw__types.html#a1ab5d42ceff21bf6a5983839ec19cdcc", null ],
      [ "dma", "group__group__hal__impl__hw__types.html#a9b7bf7fcde35981ece224554ad22f10d", null ],
      [ "source", "group__group__hal__impl__hw__types.html#ad47bf766941c1d44e67e70bbc239c607", null ],
      [ "async_buff_orig", "group__group__hal__impl__hw__types.html#af162a27f19cd19a089fb5e2c49ae800a", null ]
    ] ],
    [ "cyhal_adc_configurator_t", "group__group__hal__impl__hw__types.html#structcyhal__adc__configurator__t", [
      [ "empty", "group__group__hal__impl__hw__types.html#a3b1e2aeb8c2f6bfc57ed1a1885f013e7", null ]
    ] ],
    [ "cyhal_adc_channel_t", "group__group__hal__impl__hw__types.html#structcyhal__adc__channel__t", [
      [ "adc", "group__group__hal__impl__hw__types.html#ae3f5aaa0bc16116937f581313a9a88cf", null ],
      [ "vplus", "group__group__hal__impl__hw__types.html#aa6c3e0cbeff34ed618b0408597443ed3", null ],
      [ "channel_idx", "group__group__hal__impl__hw__types.html#a6bf6a5d80c620d0c1ffd7e281f4ff5e1", null ],
      [ "vminus", "group__group__hal__impl__hw__types.html#abcc1d2644dbd56211ea3c8741fdf9178", null ],
      [ "minimum_acquisition_ns", "group__group__hal__impl__hw__types.html#a03534d0f3db39a0495245a42d69eb13c", null ]
    ] ],
    [ "cyhal_comp_t", "group__group__hal__impl__hw__types.html#structcyhal__comp__t", [
      [ "owned_by_configurator", "group__group__hal__impl__hw__types.html#a405afe32fbfe45a4355845c295b7e763", null ],
      [ "resource", "group__group__hal__impl__hw__types.html#abfdfcd88b2f9058b88fcd385a412b578", null ],
      [ "pin_vin_p", "group__group__hal__impl__hw__types.html#a253387985e2368023e82f4d519448b7b", null ],
      [ "pin_vin_m", "group__group__hal__impl__hw__types.html#a529ba908b202f3e94240b26a92be90f9", null ],
      [ "pin_out", "group__group__hal__impl__hw__types.html#acbe031d28cebcf3212482c98af7c3fc4", null ],
      [ "callback_data", "group__group__hal__impl__hw__types.html#a62e44a6d43bc091a5c31cea999aefabe", null ],
      [ "irq_cause", "group__group__hal__impl__hw__types.html#ac1cc4c9fa610791f2d51a84bed89fd6d", null ]
    ] ],
    [ "cyhal_comp_t.__unnamed__", "group__group__hal__impl__hw__types.html#unioncyhal__comp__t_8____unnamed____", [
      [ "base_lpcomp", "group__group__hal__impl__hw__types.html#a0deb488364ff2caa9ee5f6413710ffc9", null ]
    ] ],
    [ "cyhal_comp_configurator_t", "group__group__hal__impl__hw__types.html#structcyhal__comp__configurator__t", [
      [ "empty", "group__group__hal__impl__hw__types.html#a5e2f7c211530527474a58cca8ebe0493", null ]
    ] ],
    [ "cyhal_crc_t", "group__group__hal__impl__hw__types.html#structcyhal__crc__t", [
      [ "base", "group__group__hal__impl__hw__types.html#aa8172d5f14d9a24826e003df016ea62d", null ],
      [ "resource", "group__group__hal__impl__hw__types.html#aac1de671fc1cf74d6808fd126fe89238", null ],
      [ "crc_width", "group__group__hal__impl__hw__types.html#a6e9f1abc6fc3e175b4d6536a050d320f", null ]
    ] ],
    [ "cyhal_dac_t", "group__group__hal__impl__hw__types.html#structcyhal__dac__t", [
      [ "owned_by_configurator", "group__group__hal__impl__hw__types.html#adf83c59dbfc0e49bce083ca0b24621e8", null ],
      [ "base_dac", "group__group__hal__impl__hw__types.html#a5b0e17875a2da127bcdbaeb51f5a66c1", null ],
      [ "base_opamp", "group__group__hal__impl__hw__types.html#a143f8ee01aefa9db1120ef8851efe5bc", null ],
      [ "resource_dac", "group__group__hal__impl__hw__types.html#ac8e0a257738d4a4fe97862e3e177ab2e", null ],
      [ "resource_opamp", "group__group__hal__impl__hw__types.html#af45e23f1a63602534c1306cbb8038fc3", null ],
      [ "resource_aref_opamp", "group__group__hal__impl__hw__types.html#aec0112cc65bfebc5669e436c9b877727", null ],
      [ "pin", "group__group__hal__impl__hw__types.html#a7e9694b84de60b955ff0d8a6afbc55c2", null ]
    ] ],
    [ "cyhal_dac_configurator_t", "group__group__hal__impl__hw__types.html#structcyhal__dac__configurator__t", [
      [ "empty", "group__group__hal__impl__hw__types.html#aa43ffa9cb2b9004f51598505bcd18a85", null ]
    ] ],
    [ "cyhal_opamp_t", "group__group__hal__impl__hw__types.html#structcyhal__opamp__t", [
      [ "empty", "group__group__hal__impl__hw__types.html#a3a6e0147f14eeb36a7f4f969f114da1e", null ]
    ] ],
    [ "cyhal_opamp_configurator_t", "group__group__hal__impl__hw__types.html#structcyhal__opamp__configurator__t", [
      [ "empty", "group__group__hal__impl__hw__types.html#a2ab3f37f832b96099be3a642b2cdf20f", null ]
    ] ],
    [ "cyhal_flash_t", "group__group__hal__impl__hw__types.html#structcyhal__flash__t", [
      [ "empty", "group__group__hal__impl__hw__types.html#aaa4efca804da27aa9934f5bc2a88b609", null ]
    ] ],
    [ "cyhal_i2c_t", "group__group__hal__impl__hw__types.html#structcyhal__i2c__t", [
      [ "base", "group__group__hal__impl__hw__types.html#a0929625ac8253a070d2edb3cc3c1bd4e", null ],
      [ "resource", "group__group__hal__impl__hw__types.html#a34241849f682fd5bee4f6b7be9c5e44d", null ],
      [ "pin_sda", "group__group__hal__impl__hw__types.html#ab6d7b3f033a28dd9589d765d3c12e758", null ],
      [ "pin_scl", "group__group__hal__impl__hw__types.html#ae48ab483971698a3695c2145e1eafe28", null ],
      [ "clock", "group__group__hal__impl__hw__types.html#aba31f83dc1b34b7adef74c7828892156", null ],
      [ "is_clock_owned", "group__group__hal__impl__hw__types.html#a171ccacd621ee02fb4e29af9cb833b38", null ],
      [ "context", "group__group__hal__impl__hw__types.html#aa56649f560fd041a0b1303921e2ba3fa", null ],
      [ "rx_config", "group__group__hal__impl__hw__types.html#a43ab6f2f527440a244846ee58b1e903d", null ],
      [ "tx_config", "group__group__hal__impl__hw__types.html#aace0bcce15d6519d9d7edf4470719b68", null ],
      [ "irq_cause", "group__group__hal__impl__hw__types.html#a74a6c300ca7a9aab30886a343e1c6d19", null ],
      [ "pending", "group__group__hal__impl__hw__types.html#ade05e50ecdc505da34ca7a0cc190d7fd", null ],
      [ "callback_data", "group__group__hal__impl__hw__types.html#aaaab9b7e79c057162b0f000e0502295c", null ],
      [ "dc_configured", "group__group__hal__impl__hw__types.html#a19704eef9bce9e22d844f6b7f34bdbe1", null ]
    ] ],
    [ "cyhal_i2c_configurator_t", "group__group__hal__impl__hw__types.html#structcyhal__i2c__configurator__t", [
      [ "resource", "group__group__hal__impl__hw__types.html#aed4111108b087f3ce8a7c476cc7794b3", null ],
      [ "config", "group__group__hal__impl__hw__types.html#ad7ea13b8503dd3b8c79aeb61cb164018", null ],
      [ "clock", "group__group__hal__impl__hw__types.html#a1057a27d588756467105a0bbc14ab6f2", null ]
    ] ],
    [ "cyhal_ezi2c_t", "group__group__hal__impl__hw__types.html#structcyhal__ezi2c__t", [
      [ "base", "group__group__hal__impl__hw__types.html#a1acfb04d7f408bef718b8fc65d3e51ce", null ],
      [ "resource", "group__group__hal__impl__hw__types.html#a9c99de3b28996d598c0bfff24553fe78", null ],
      [ "pin_sda", "group__group__hal__impl__hw__types.html#a28cfb1d3efde5f9680cc1da02804cb34", null ],
      [ "pin_scl", "group__group__hal__impl__hw__types.html#a75b314887d1fcaaaba028873a3f1292d", null ],
      [ "clock", "group__group__hal__impl__hw__types.html#a68627f300a191617cf6d7f49e3d115d4", null ],
      [ "is_clock_owned", "group__group__hal__impl__hw__types.html#a5319683ddb6cfb91beca86ac479ebe37", null ],
      [ "context", "group__group__hal__impl__hw__types.html#a3aa065ed0c7c1d4d24c559cc4f4a644b", null ],
      [ "irq_cause", "group__group__hal__impl__hw__types.html#a9cded0c71c054dea98ddf9f0c68d5ff7", null ],
      [ "callback_data", "group__group__hal__impl__hw__types.html#a78fc15a46183b145984ad509e430d8af", null ],
      [ "two_addresses", "group__group__hal__impl__hw__types.html#ac6071807748291847adea1e99556399c", null ],
      [ "dc_configured", "group__group__hal__impl__hw__types.html#ab117f60bef3a1cee1174c54143f88f81", null ]
    ] ],
    [ "cyhal_ezi2c_configurator_t", "group__group__hal__impl__hw__types.html#structcyhal__ezi2c__configurator__t", [
      [ "resource", "group__group__hal__impl__hw__types.html#ac82d894adda382194f2cf0e6bbbf187c", null ],
      [ "config", "group__group__hal__impl__hw__types.html#a8c6cdd3c0d2d74799b69cd6828dbc6ec", null ],
      [ "clock", "group__group__hal__impl__hw__types.html#a03a898a051b20553077322e9397eeb16", null ]
    ] ],
    [ "cyhal_keyscan_t", "group__group__hal__impl__hw__types.html#structcyhal__keyscan__t", [
      [ "empty", "group__group__hal__impl__hw__types.html#a9e691cfada88c6ac502b18667761a681", null ]
    ] ],
    [ "cyhal_keyscan_configurator_t", "group__group__hal__impl__hw__types.html#structcyhal__keyscan__configurator__t", [
      [ "empty", "group__group__hal__impl__hw__types.html#a8adc8ee6dd29633613711d8fe55b71cd", null ]
    ] ],
    [ "cyhal_lptimer_t", "group__group__hal__impl__hw__types.html#structcyhal__lptimer__t", [
      [ "base", "group__group__hal__impl__hw__types.html#ab6e909cedc7f2a404a5de186d7c731cb", null ],
      [ "resource", "group__group__hal__impl__hw__types.html#a06e532202124b44f3cbd3a88270f50ae", null ],
      [ "callback_data", "group__group__hal__impl__hw__types.html#aee76c50832553de4525a4270d5d06df5", null ],
      [ "clear_int_mask", "group__group__hal__impl__hw__types.html#a0267197c10e521c17927a135956c7e31", null ],
      [ "isr_call_user_cb", "group__group__hal__impl__hw__types.html#ab62c0a56c05ca7bebd85e2e2e1f33ff4", null ]
    ] ],
    [ "cyhal_pdm_pcm_t", "group__group__hal__impl__hw__types.html#structcyhal__pdm__pcm__t", [
      [ "owned_by_configurator", "group__group__hal__impl__hw__types.html#af9db152962ccdd77fb25cb6d1900ac37", null ],
      [ "base", "group__group__hal__impl__hw__types.html#ad96e08de632111cb6c4b51212270d49c", null ],
      [ "resource", "group__group__hal__impl__hw__types.html#a02d5e79f65e4d59fee8b32777d86cd1b", null ],
      [ "pin_data", "group__group__hal__impl__hw__types.html#a23b0819374a1197586fa47196c1d5c28", null ],
      [ "pin_clk", "group__group__hal__impl__hw__types.html#a5bda25c3b6a6a3af16cb102e29696a69", null ],
      [ "clock", "group__group__hal__impl__hw__types.html#a840ad1ac3cc05d9c732dd7d4f78a0002", null ],
      [ "is_clock_owned", "group__group__hal__impl__hw__types.html#a6739c9fea07cfd73598c1f6590a77e28", null ],
      [ "user_trigger_level", "group__group__hal__impl__hw__types.html#a7370c5d874b9ec87fb1838d0c54afa93", null ],
      [ "irq_cause", "group__group__hal__impl__hw__types.html#a459a288e12f28d84eba07b731557f6c7", null ],
      [ "callback_data", "group__group__hal__impl__hw__types.html#a6e777ed7780a0b6843f11664a490898f", null ],
      [ "word_size", "group__group__hal__impl__hw__types.html#aede94648d66301bb1b626f6cec71e344", null ],
      [ "dma", "group__group__hal__impl__hw__types.html#a1ed94b4e2288e0e7c6b71535258b469a", null ],
      [ "stabilized", "group__group__hal__impl__hw__types.html#a882b2be28778d26c7872f52f587dacce", null ],
      [ "pm_transition_ready", "group__group__hal__impl__hw__types.html#a552d58a6a7db7165c25c6118e9f378d9", null ],
      [ "pm_callback", "group__group__hal__impl__hw__types.html#a3bb17483581fb05866d9aa744a4d9079", null ],
      [ "async_buffer", "group__group__hal__impl__hw__types.html#ae5a3543635ef4f259fd7047663653465", null ],
      [ "async_read_remaining", "group__group__hal__impl__hw__types.html#a706a2bf50cce1bebabf22f563f8ce917", null ]
    ] ],
    [ "cyhal_pdm_pcm_configurator_t", "group__group__hal__impl__hw__types.html#structcyhal__pdm__pcm__configurator__t", [
      [ "resource", "group__group__hal__impl__hw__types.html#a73023a16c5579e499e07be7e9705a2ac", null ],
      [ "config", "group__group__hal__impl__hw__types.html#ab82d7607d1152c7f798a6ba9b726edf6", null ],
      [ "clock", "group__group__hal__impl__hw__types.html#af503ea67e6064c475584c50bcb326ced", null ]
    ] ],
    [ "cyhal_pwm_t", "group__group__hal__impl__hw__types.html#structcyhal__pwm__t", [
      [ "tcpwm", "group__group__hal__impl__hw__types.html#a2256866da49cb401cc0c792d184aa13d", null ],
      [ "pin", "group__group__hal__impl__hw__types.html#adbc3775af399b89b28f710ba299e633e", null ],
      [ "pin_compl", "group__group__hal__impl__hw__types.html#acd470392a044f5d9e89462be54e54516", null ]
    ] ],
    [ "cyhal_pwm_configurator_t", "group__group__hal__impl__hw__types.html#structcyhal__pwm__configurator__t", [
      [ "empty", "group__group__hal__impl__hw__types.html#a19632194ec58554c2d0eb3df6f02301d", null ]
    ] ],
    [ "cyhal_qspi_t", "group__group__hal__impl__hw__types.html#structcyhal__qspi__t", [
      [ "base", "group__group__hal__impl__hw__types.html#a7d4a257b40a90d8df5f2078c333be024", null ],
      [ "resource", "group__group__hal__impl__hw__types.html#ac59d6d6a74889f341406e5abafa07625", null ],
      [ "pin_sclk", "group__group__hal__impl__hw__types.html#a69cf396fb94143caf3c17f21e77fe30a", null ],
      [ "saved_sclk_hsiom", "group__group__hal__impl__hw__types.html#a039d89e76b2eb6fae1c3b335ae173f96", null ],
      [ "pin_io", "group__group__hal__impl__hw__types.html#a556407df4cdf8806240013d62edd1c8b", null ],
      [ "saved_io_hsiom", "group__group__hal__impl__hw__types.html#a161c05ae3ec11cec6b164fb0ed1110c9", null ],
      [ "pin_ssel", "group__group__hal__impl__hw__types.html#a09ac9cc8aaeb58965a786f5a02747715", null ],
      [ "saved_ssel_hsiom", "group__group__hal__impl__hw__types.html#ad64f4c66642ffc40777dd6ccb1401950", null ],
      [ "slave_select", "group__group__hal__impl__hw__types.html#a03a0419ecb43ffc36c7d6f407f49fc9d", null ],
      [ "clock", "group__group__hal__impl__hw__types.html#a28e2c55bdc9721139219fd2bfc7dbd6e", null ],
      [ "is_clock_owned", "group__group__hal__impl__hw__types.html#a58c5363b600cf045c3594385f107b727", null ],
      [ "mode", "group__group__hal__impl__hw__types.html#a32c76b6134b5fcfc5ed7a5bed1ebe93d", null ],
      [ "context", "group__group__hal__impl__hw__types.html#a701c962e05235ae4d577fd2831df2f1a", null ],
      [ "irq_cause", "group__group__hal__impl__hw__types.html#a6e5636079826219fc50c6eca3d0b42ba", null ],
      [ "callback_data", "group__group__hal__impl__hw__types.html#a548bcda97b2206efadd024b69339973a", null ],
      [ "pm_callback", "group__group__hal__impl__hw__types.html#a629d4ffdad4e9a8912cc08cfb8b94f9b", null ],
      [ "pm_transition_pending", "group__group__hal__impl__hw__types.html#a5271ef0f6b8a86eaefba25d7880f9f88", null ],
      [ "dc_configured", "group__group__hal__impl__hw__types.html#a054f33c10bb0572ba30dfe59eff420fa", null ]
    ] ],
    [ "cyhal_qspi_configurator_t", "group__group__hal__impl__hw__types.html#structcyhal__qspi__configurator__t", [
      [ "resource", "group__group__hal__impl__hw__types.html#a3ede7981929f58bad96282751a9252bb", null ],
      [ "config", "group__group__hal__impl__hw__types.html#a4917d046199e2648a285101717b7c322", null ],
      [ "clock", "group__group__hal__impl__hw__types.html#a175cdebfe3e4c2cedd3d9f1d7e9c1bb5", null ],
      [ "gpios", "group__group__hal__impl__hw__types.html#a936f73fd28dcf5f0c35a30d324fc4886", null ],
      [ "irqs", "group__group__hal__impl__hw__types.html#a2f9f081df171d440de1ae697c7acf4fc", null ],
      [ "dmas", "group__group__hal__impl__hw__types.html#aa3d04d8897cf94a950572129dd7e3c5b", null ]
    ] ],
    [ "cyhal_qspi_configurator_t.gpios", "group__group__hal__impl__hw__types.html#structcyhal__qspi__configurator__t_8gpios", [
      [ "sclk", "group__group__hal__impl__hw__types.html#af872f42cc51cf7029acc607881b3c72b", null ],
      [ "ssel", "group__group__hal__impl__hw__types.html#a0c20fd974ba0bcf95fe52c32f6c723d6", null ],
      [ "io", "group__group__hal__impl__hw__types.html#a3e4565181214193ebaf269804f808cd9", null ]
    ] ],
    [ "cyhal_quaddec_t", "group__group__hal__impl__hw__types.html#structcyhal__quaddec__t", [
      [ "tcpwm", "group__group__hal__impl__hw__types.html#a43b3afb6a641da8607d642d8d68264b3", null ],
      [ "phi_a", "group__group__hal__impl__hw__types.html#a294599f4c399f8cd722db5b72bd6f60a", null ],
      [ "phi_b", "group__group__hal__impl__hw__types.html#aedbae5253d7f7a9c2f9b02d0f1d4e856", null ],
      [ "index", "group__group__hal__impl__hw__types.html#a6dd26d89e16c27595a35fd8c9a738035", null ],
      [ "last_counter_value", "group__group__hal__impl__hw__types.html#aa02669222b74cc12e1b1442e13604188", null ]
    ] ],
    [ "cyhal_quaddec_configurator_t", "group__group__hal__impl__hw__types.html#structcyhal__quaddec__configurator__t", [
      [ "empty", "group__group__hal__impl__hw__types.html#afd0b75c559b6c7cff88c5b13c103db43", null ]
    ] ],
    [ "cyhal_trng_t", "group__group__hal__impl__hw__types.html#structcyhal__trng__t", [
      [ "base", "group__group__hal__impl__hw__types.html#acf8a5871571c60e989496cefe80df53f", null ],
      [ "resource", "group__group__hal__impl__hw__types.html#adff657185b0e7645d799377dedc5eaf6", null ]
    ] ],
    [ "cyhal_rtc_t", "group__group__hal__impl__hw__types.html#structcyhal__rtc__t", [
      [ "empty", "group__group__hal__impl__hw__types.html#aff21062458721c4f2e7cc6eb9700f815", null ]
    ] ],
    [ "cyhal_rtc_configurator_t", "group__group__hal__impl__hw__types.html#structcyhal__rtc__configurator__t", [
      [ "empty", "group__group__hal__impl__hw__types.html#ae51bdca55b266f02279b6ce1e6fa468b", null ]
    ] ],
    [ "_cyhal_sdxx_t", "group__group__hal__impl__hw__types.html#struct__cyhal__sdxx__t", [
      [ "is_sdio", "group__group__hal__impl__hw__types.html#a901be7064b4ef2125a0d0cacb5dd0c75", null ],
      [ "obj", "group__group__hal__impl__hw__types.html#abdbecd0c8317bbf500445a6ee174f606", null ],
      [ "base", "group__group__hal__impl__hw__types.html#a77e907c6d45ca8298af1433952430cdd", null ],
      [ "resource", "group__group__hal__impl__hw__types.html#af1a7fdcd6b75bfc60590cf44d3a12904", null ],
      [ "context", "group__group__hal__impl__hw__types.html#a7132c5ffc0587bcadf3f5c4b76dace6e", null ],
      [ "clock", "group__group__hal__impl__hw__types.html#a8c2d70c8dc253e1a6d38f6436ea9de28", null ],
      [ "emmc", "group__group__hal__impl__hw__types.html#af6a7817cb8032f7bb93754a0dd0991da", null ],
      [ "dma_type", "group__group__hal__impl__hw__types.html#a3cd47abb68c0b7ef9fd8a50cc19852fb", null ],
      [ "adma_descriptor_tbl", "group__group__hal__impl__hw__types.html#a138725509b638e4c84a11ac1f7b73569", null ],
      [ "data_transfer_status", "group__group__hal__impl__hw__types.html#a9f7f4b21b3e34415004f93e8e597f3d3", null ],
      [ "pin_clk", "group__group__hal__impl__hw__types.html#a495550c5bbda030eda3dd49c6d469fbf", null ],
      [ "pin_cmd", "group__group__hal__impl__hw__types.html#a04635b31c16b7864127824136ce423bf", null ],
      [ "pin_io_vol_sel", "group__group__hal__impl__hw__types.html#a877a8791ee777b16c78fc0b3e3322b77", null ],
      [ "low_voltage_io_set", "group__group__hal__impl__hw__types.html#a4f803ba61f370d478e2fc33bec21f18a", null ],
      [ "irq_cause", "group__group__hal__impl__hw__types.html#af426294b315b7e5f144fd51b239c50f4", null ],
      [ "callback_data", "group__group__hal__impl__hw__types.html#ae274122a23160c5e4a06c1ef68617c46", null ],
      [ "pm_transition_pending", "group__group__hal__impl__hw__types.html#a3c77857a6e28d5bb1a3d2d200a61924e", null ],
      [ "pm_callback_data", "group__group__hal__impl__hw__types.html#acf5a2d09cbbe402918de8bfaea65500f", null ],
      [ "dc_configured", "group__group__hal__impl__hw__types.html#a981aedc21134e1a6fcf4efb3f5fe7140", null ],
      [ "clock_owned", "group__group__hal__impl__hw__types.html#a945e014c40dfd0875004f1e0ea528c5e", null ]
    ] ],
    [ "cyhal_sdhc_t", "group__group__hal__impl__hw__types.html#structcyhal__sdhc__t", [
      [ "sdxx", "group__group__hal__impl__hw__types.html#aa5b3664f028af4147ff072d48744fc1f", null ],
      [ "bus_width", "group__group__hal__impl__hw__types.html#ae5c013a3da89c3a2c1d0217505b21330", null ],
      [ "enable_led_control", "group__group__hal__impl__hw__types.html#a891c4ab59571baa487e41a8ac5ac93e8", null ],
      [ "data_timeout_tout", "group__group__hal__impl__hw__types.html#afbe72cbfaac37d7f9a1ba3bf43f3ba43", null ],
      [ "data_timeout_auto_reconfig", "group__group__hal__impl__hw__types.html#ae4e219aa427c728d6b42ec01d4560877", null ],
      [ "data_timeout_card_clocks_user", "group__group__hal__impl__hw__types.html#a9026782c36f460206f0dc410fb32feb2", null ],
      [ "pin_data", "group__group__hal__impl__hw__types.html#a072f05e510d39475bc879745f8f67346", null ],
      [ "pin_card_detect", "group__group__hal__impl__hw__types.html#a9c730d74dc6e5e258f9c7cdb82549814", null ],
      [ "pin_card_pwr_en", "group__group__hal__impl__hw__types.html#a80635caa361609e72fda9163312e2772", null ],
      [ "pin_card_mech_write_prot", "group__group__hal__impl__hw__types.html#a6ff0582126f8d4455bd71ff4b9108a28", null ],
      [ "pin_led_ctrl", "group__group__hal__impl__hw__types.html#aeb60d24a9281ac912f7b2fe3a194ff89", null ],
      [ "pin_emmc_reset", "group__group__hal__impl__hw__types.html#a1448e31374d69a2a064a1e53ea967cf9", null ],
      [ "low_voltage_io_desired", "group__group__hal__impl__hw__types.html#ad47710c0eec4445c508bb3d86163e67e", null ],
      [ "bus_frequency_hz", "group__group__hal__impl__hw__types.html#a2e0ffedf964bbd36035d15d56fcd52bd", null ],
      [ "block_source_freq_hz", "group__group__hal__impl__hw__types.html#ad2a543b3fa9b96fd88604af32a24adac", null ],
      [ "card_detect_cb", "group__group__hal__impl__hw__types.html#a1edd05a64e16a132c65de48a72e2f8ba", null ],
      [ "cd_gpio_cb_enabled", "group__group__hal__impl__hw__types.html#a3583336aa27c66db9b047bb898f5d9bc", null ],
      [ "emmc_generic_cmd6_time_ms", "group__group__hal__impl__hw__types.html#a49722e705b3879179a4c0e733216e3ab", null ]
    ] ],
    [ "cyhal_sdhc_t_gpio_cb", "group__group__hal__impl__hw__types.html#structcyhal__sdhc__t_1_1cyhal__sdhc__t__gpio__cb", [
      [ "callback", "group__group__hal__impl__hw__types.html#a1bab6c1fc141d37de11b9260a1a4092f", null ],
      [ "callback_arg", "group__group__hal__impl__hw__types.html#a5365a002d4eeae93d13b0aa6b0f04e9b", null ],
      [ "next", "group__group__hal__impl__hw__types.html#a2191953f05f4c3c3c1a68c64cd0cfeda", null ],
      [ "pin", "group__group__hal__impl__hw__types.html#a885e6b539e8ab47be85330609404ee01", null ]
    ] ],
    [ "cyhal_sdhc_configurator_t", "group__group__hal__impl__hw__types.html#structcyhal__sdhc__configurator__t", [
      [ "resource", "group__group__hal__impl__hw__types.html#ab67cc2aae640913c4e34510475c52db5", null ],
      [ "host_config", "group__group__hal__impl__hw__types.html#a2fecaf2a2c3bd0279d265aabfa4e44b1", null ],
      [ "card_config", "group__group__hal__impl__hw__types.html#a22e2164e32a8b09388bc4aa4e10dd900", null ],
      [ "clock", "group__group__hal__impl__hw__types.html#aec900704962f94c5cb8307fe3c96616f", null ],
      [ "gpios", "group__group__hal__impl__hw__types.html#ac413cf7cd7ac66ac325ba3177844b244", null ]
    ] ],
    [ "cyhal_sdhc_configurator_t.gpios", "group__group__hal__impl__hw__types.html#structcyhal__sdhc__configurator__t_8gpios", [
      [ "clk", "group__group__hal__impl__hw__types.html#a0a3bc2148686f2b562665c3891507e35", null ],
      [ "cmd", "group__group__hal__impl__hw__types.html#adfff0a7fa1a55c8c1a4966c19f6da452", null ],
      [ "data", "group__group__hal__impl__hw__types.html#a63ed1b8883d72f6c440cbe698a0486fd", null ],
      [ "card_detect", "group__group__hal__impl__hw__types.html#aa40afde80079859f963b284408cc3f6d", null ],
      [ "io_volt_sel", "group__group__hal__impl__hw__types.html#a9481ab5209a8e69d08eee933b3a64d05", null ],
      [ "card_pwr_en", "group__group__hal__impl__hw__types.html#a42d250cbb964efb13be3e420946c0698", null ],
      [ "card_mech_write_prot", "group__group__hal__impl__hw__types.html#a3278846bce18bbb3e0c2f9c807781907", null ],
      [ "led_ctrl", "group__group__hal__impl__hw__types.html#a70bc5a3d045210827230109192236e26", null ],
      [ "emmc_reset", "group__group__hal__impl__hw__types.html#a8d31b4a17ef1a580f853b0a4fab1bafd", null ]
    ] ],
    [ "cyhal_sdio_t", "group__group__hal__impl__hw__types.html#structcyhal__sdio__t", [
      [ "sdxx", "group__group__hal__impl__hw__types.html#a7dc61ee06c96ec5f8b4b516927880aae", null ],
      [ "dc_configured", "group__group__hal__impl__hw__types.html#a82648dd6d1d3deeba634bd60bc105982", null ],
      [ "clock_owned", "group__group__hal__impl__hw__types.html#a40d9a355c7a0195e9df51daac8cf9638", null ],
      [ "pin_data0", "group__group__hal__impl__hw__types.html#ae6e6a56a702ec396296b3157a2461077", null ],
      [ "pin_data1", "group__group__hal__impl__hw__types.html#a0d6a82b63f847fd52e6f9834c257d568", null ],
      [ "pin_data2", "group__group__hal__impl__hw__types.html#a933ec9a436f9ddd1ee2321871bdcbf5f", null ],
      [ "pin_data3", "group__group__hal__impl__hw__types.html#a9268ca2e6abbe7873c914ce6cb85d18d", null ],
      [ "frequencyhal_hz", "group__group__hal__impl__hw__types.html#a1575bc5e8889960f5d34d3e7926a1931", null ],
      [ "block_size", "group__group__hal__impl__hw__types.html#aff42f0fd4ff5e0026f7532469d829f08", null ],
      [ "events", "group__group__hal__impl__hw__types.html#acb9a4e41a6c52418ccd92285f5eadde0", null ]
    ] ],
    [ "cyhal_sdio_configurator_t", "group__group__hal__impl__hw__types.html#structcyhal__sdio__configurator__t", [
      [ "resource", "group__group__hal__impl__hw__types.html#aeefe18394f466d40453cb76d2c953be2", null ],
      [ "host_config", "group__group__hal__impl__hw__types.html#ae3f0ff1a72b28635eb358d805bb42fe7", null ],
      [ "card_config", "group__group__hal__impl__hw__types.html#ae81237c54251cdb90ea50f82505b88e8", null ],
      [ "clock", "group__group__hal__impl__hw__types.html#a4473c510953067b0933c989e461f9534", null ],
      [ "gpios", "group__group__hal__impl__hw__types.html#adab1fcbdf915199b7860cc65c5f071b3", null ]
    ] ],
    [ "cyhal_sdio_configurator_t.gpios", "group__group__hal__impl__hw__types.html#structcyhal__sdio__configurator__t_8gpios", [
      [ "clk", "group__group__hal__impl__hw__types.html#a0a3bc2148686f2b562665c3891507e35", null ],
      [ "cmd", "group__group__hal__impl__hw__types.html#adfff0a7fa1a55c8c1a4966c19f6da452", null ],
      [ "data", "group__group__hal__impl__hw__types.html#a3fbd200a7024d776bc2a6eae2ca0c5b7", null ]
    ] ],
    [ "cyhal_spi_t", "group__group__hal__impl__hw__types.html#structcyhal__spi__t", [
      [ "base", "group__group__hal__impl__hw__types.html#a9d0c88aefd98c3154063d62806bc7896", null ],
      [ "resource", "group__group__hal__impl__hw__types.html#a50ef30629c0ed6b9b88fd3edd1d6d917", null ],
      [ "pin_miso", "group__group__hal__impl__hw__types.html#a4abba543deddc161985cb5e2bce54a27", null ],
      [ "pin_mosi", "group__group__hal__impl__hw__types.html#aeb604dd90daa694e30c9401c4a35a261", null ],
      [ "pin_sclk", "group__group__hal__impl__hw__types.html#a0257721a8d77e714a2403d20c474097b", null ],
      [ "pin_ssel", "group__group__hal__impl__hw__types.html#a25f5477edefe12fe9e7c0fc5a34e5c3d", null ],
      [ "ssel_pol", "group__group__hal__impl__hw__types.html#a97c4443efbfb39aa679ab01dda84c7f9", null ],
      [ "active_ssel", "group__group__hal__impl__hw__types.html#aadd316efc500c86d31d4f5a1d537eda8", null ],
      [ "clock", "group__group__hal__impl__hw__types.html#a209a4ab790591cf161bd9cd4984cac94", null ],
      [ "clk_mode", "group__group__hal__impl__hw__types.html#a53afd13ba64fe0511d4e6a18e1e0e5de", null ],
      [ "mode", "group__group__hal__impl__hw__types.html#a48e2879bfa6bea23645f5e2b8a684eb9", null ],
      [ "data_bits", "group__group__hal__impl__hw__types.html#a50a0b5cf864a709a12c53b57bf1f60e0", null ],
      [ "is_slave", "group__group__hal__impl__hw__types.html#adac2b2d71c8aa2918756ff15b7eed46f", null ],
      [ "alloc_clock", "group__group__hal__impl__hw__types.html#ae7b748656fdeb754c3d5e4fca97ce981", null ],
      [ "oversample_value", "group__group__hal__impl__hw__types.html#a1719642510d5c74a45fc5ed4e3af0b4c", null ],
      [ "msb_first", "group__group__hal__impl__hw__types.html#ad3b024dc55f4ba25ae9a002fdf6274ef", null ],
      [ "context", "group__group__hal__impl__hw__types.html#a9d3190844992b833c1985a0f70db0f47", null ],
      [ "irq_cause", "group__group__hal__impl__hw__types.html#aaad3adf0f7954bb7fee6e543220b2c38", null ],
      [ "pending", "group__group__hal__impl__hw__types.html#a81a81ef012f522585a7f86211d2eed93", null ],
      [ "write_fill", "group__group__hal__impl__hw__types.html#a39beabda44550039d6b984c454c798e0", null ],
      [ "rx_buffer", "group__group__hal__impl__hw__types.html#ad61070aa55e039d0f02e7e4a9547bf49", null ],
      [ "rx_buffer_size", "group__group__hal__impl__hw__types.html#ae83a2c35e45a21c0bb078cfcf915b981", null ],
      [ "tx_buffer", "group__group__hal__impl__hw__types.html#a5b27c2bab5d173ffdc1187b153859f3c", null ],
      [ "tx_buffer_size", "group__group__hal__impl__hw__types.html#a68458b1ec4318a905b47e78874b9571d", null ],
      [ "is_async", "group__group__hal__impl__hw__types.html#ae332bc5a8e1965808c24eb36f7f4be01", null ],
      [ "callback_data", "group__group__hal__impl__hw__types.html#a81359f063c7f6603a9665c2af197595e", null ],
      [ "dc_configured", "group__group__hal__impl__hw__types.html#ac630c2702f0caab4a10e16e4fbbda690", null ]
    ] ],
    [ "cyhal_spi_configurator_t", "group__group__hal__impl__hw__types.html#structcyhal__spi__configurator__t", [
      [ "resource", "group__group__hal__impl__hw__types.html#a0eb4fdb582586b0a01b007e86fd924d7", null ],
      [ "config", "group__group__hal__impl__hw__types.html#a4b00937cb6ea03c1c7e4b08c772592b2", null ],
      [ "clock", "group__group__hal__impl__hw__types.html#a40b84ae49dfee0ba05fdb026d66f6411", null ],
      [ "gpios", "group__group__hal__impl__hw__types.html#a93ae57fe015a947cfc38b66c7faae538", null ]
    ] ],
    [ "cyhal_spi_configurator_t.gpios", "group__group__hal__impl__hw__types.html#structcyhal__spi__configurator__t_8gpios", [
      [ "sclk", "group__group__hal__impl__hw__types.html#af872f42cc51cf7029acc607881b3c72b", null ],
      [ "ssel", "group__group__hal__impl__hw__types.html#a0c20fd974ba0bcf95fe52c32f6c723d6", null ],
      [ "mosi", "group__group__hal__impl__hw__types.html#ac4388174c77e6510e828cb9d53d16dcc", null ],
      [ "miso", "group__group__hal__impl__hw__types.html#ae2061ec2dfba21931ffacc217340c02c", null ]
    ] ],
    [ "cyhal_timer_t", "group__group__hal__impl__hw__types.html#structcyhal__timer__t", [
      [ "tcpwm", "group__group__hal__impl__hw__types.html#ad9b79323e63e1fb3d8cedeb0baca175b", null ],
      [ "default_value", "group__group__hal__impl__hw__types.html#a35055537da61b0cc38799626e3ae0e6f", null ]
    ] ],
    [ "cyhal_timer_configurator_t", "group__group__hal__impl__hw__types.html#structcyhal__timer__configurator__t", [
      [ "empty", "group__group__hal__impl__hw__types.html#a40a7abd1ebc8b3d3eac33a18f97d618d", null ]
    ] ],
    [ "cyhal_uart_t", "group__group__hal__impl__hw__types.html#structcyhal__uart__t", [
      [ "base", "group__group__hal__impl__hw__types.html#adb1e03e9a708b3dd6aed68e6581a463a", null ],
      [ "resource", "group__group__hal__impl__hw__types.html#a8500bcc4df32b74911f7f2c7e620e609", null ],
      [ "pin_rx", "group__group__hal__impl__hw__types.html#aa211e6d348346ecb7391dfc07df98454", null ],
      [ "pin_tx", "group__group__hal__impl__hw__types.html#a934295a171024345bf34fb06d79572dc", null ],
      [ "pin_cts", "group__group__hal__impl__hw__types.html#a8b5b034b002f4e0f8070705fe4e79cc0", null ],
      [ "pin_rts", "group__group__hal__impl__hw__types.html#a7620d3f9a57ea1299c92d34229d126c3", null ],
      [ "cts_enabled", "group__group__hal__impl__hw__types.html#a535cc1f808cd288ab2738cb4cbc42e10", null ],
      [ "rts_enabled", "group__group__hal__impl__hw__types.html#ab97d9b6a2c6b33857a06f6b7bfb81560", null ],
      [ "is_clock_owned", "group__group__hal__impl__hw__types.html#ac54034503d41ea66984f5b013bf24d6e", null ],
      [ "clock", "group__group__hal__impl__hw__types.html#aa8af046d01fd941ec033e42270fabe76", null ],
      [ "context", "group__group__hal__impl__hw__types.html#a697fcf1b077b74a133145af1c28ac2f5", null ],
      [ "config", "group__group__hal__impl__hw__types.html#ac3dcfd1fa7e11f70bab10f0576b7c290", null ],
      [ "irq_cause", "group__group__hal__impl__hw__types.html#a1f4bed812246890c7edf9827ab4a358d", null ],
      [ "saved_tx_hsiom", "group__group__hal__impl__hw__types.html#a008b02a1e8dacd618e91a354bde6e2e8", null ],
      [ "saved_rts_hsiom", "group__group__hal__impl__hw__types.html#a5f630a9fe03003133e35606897f92c0e", null ],
      [ "callback_data", "group__group__hal__impl__hw__types.html#af4a8e8f055a31f3ed62aec9a50bc7fec", null ],
      [ "dc_configured", "group__group__hal__impl__hw__types.html#a34be883be5e5d6efb87ce1cfd3bc12a1", null ]
    ] ],
    [ "cyhal_uart_configurator_t", "group__group__hal__impl__hw__types.html#structcyhal__uart__configurator__t", [
      [ "resource", "group__group__hal__impl__hw__types.html#a9398edf0cc6815e96856f11dcf2fd668", null ],
      [ "config", "group__group__hal__impl__hw__types.html#a99a734b6082d63d2e8f9c1a1da19d2ec", null ],
      [ "clock", "group__group__hal__impl__hw__types.html#a34246d9eb60e84558e4219b7e0ec7919", null ],
      [ "gpios", "group__group__hal__impl__hw__types.html#a3b2efdb7a21663fc4e88b893c32ac049", null ]
    ] ],
    [ "cyhal_uart_configurator_t.gpios", "group__group__hal__impl__hw__types.html#structcyhal__uart__configurator__t_8gpios", [
      [ "pin_tx", "group__group__hal__impl__hw__types.html#a49340c590c40fb03215c6421871c2a4d", null ],
      [ "pin_rts", "group__group__hal__impl__hw__types.html#a5b3a0a9c2373ce0d089e7b46be0cc30a", null ],
      [ "pin_cts", "group__group__hal__impl__hw__types.html#ad98f68b774fc8a9e3b3911f98bd34268", null ]
    ] ],
    [ "cyhal_usb_dev_t", "group__group__hal__impl__hw__types.html#structcyhal__usb__dev__t", [
      [ "base", "group__group__hal__impl__hw__types.html#a3c6b9b0f98859eff39ca7f376c2282e0", null ],
      [ "context", "group__group__hal__impl__hw__types.html#a71e9161fcac9326df1d83e026ede4ada", null ],
      [ "resource", "group__group__hal__impl__hw__types.html#ac15fc6729389743f48c21e8c3e68e52e", null ],
      [ "pll_resource", "group__group__hal__impl__hw__types.html#a3a276cf5df1c7b0cea53fe44e30f53a5", null ],
      [ "clock", "group__group__hal__impl__hw__types.html#a21a1eddc7965f2c095ab57fdc891231d", null ],
      [ "shared_clock", "group__group__hal__impl__hw__types.html#a4dd7bc3028d5e9d7bc4da5bb076d83ef", null ],
      [ "pin_dp", "group__group__hal__impl__hw__types.html#a3101a7d5d01e3075613ca3e6b0b911c0", null ],
      [ "pin_dm", "group__group__hal__impl__hw__types.html#adeffee8b006f521b524e47d58e99d643", null ],
      [ "pm_callback", "group__group__hal__impl__hw__types.html#a2f6379dd475c270983fd096104b4aa21", null ],
      [ "rd_data", "group__group__hal__impl__hw__types.html#aa7973c6fcf336f6e2db8e0a123a7526d", null ],
      [ "rd_size", "group__group__hal__impl__hw__types.html#a2f579c1dfe2024e95f6a6d04a547796e", null ]
    ] ],
    [ "cyhal_wdt_t", "group__group__hal__impl__hw__types.html#structcyhal__wdt__t", [
      [ "placeholder", "group__group__hal__impl__hw__types.html#ab767afdb6a026741efa6e40457b3634e", null ]
    ] ],
    [ "CYHAL_ISR_PRIORITY_DEFAULT", "group__group__hal__impl__hw__types.html#gad822a466fc63847114add720ef84c83a", null ],
    [ "cyhal_system_callback_t", "group__group__hal__impl__hw__types.html#gacd10538852e7575732463b1f552b73d4", null ],
    [ "cyhal_i2s_t", "group__group__hal__impl__hw__types.html#ga5c90028db813f9efe2a9e95b16caded4", null ],
    [ "cyhal_i2s_configurator_t", "group__group__hal__impl__hw__types.html#ga9264445fa8d36d0ddaeb59931073ccd0", null ],
    [ "cyhal_tdm_t", "group__group__hal__impl__hw__types.html#ga0feb1843e60080c101c7a35fe884fe73", null ],
    [ "cyhal_tdm_configurator_t", "group__group__hal__impl__hw__types.html#ga4748ddbae8e13f9fe60b189349e3cdbd", null ],
    [ "cyhal_resource_t", "group__group__hal__impl__hw__types.html#ga63b023ea7b5e73db59ddc0423c77975b", [
      [ "CYHAL_RSC_ADC", "group__group__hal__impl__hw__types.html#gga63b023ea7b5e73db59ddc0423c77975ba612bee18e656ba78a4ca633f8913249d", null ],
      [ "CYHAL_RSC_ADCMIC", "group__group__hal__impl__hw__types.html#gga63b023ea7b5e73db59ddc0423c77975ba0a16c7812ccaba345ba94d92fbc3e26e", null ],
      [ "CYHAL_RSC_BLESS", "group__group__hal__impl__hw__types.html#gga63b023ea7b5e73db59ddc0423c77975bac10abc82f19b0a06a14a98e30a75b74d", null ],
      [ "CYHAL_RSC_CAN", "group__group__hal__impl__hw__types.html#gga63b023ea7b5e73db59ddc0423c77975ba1b775f74aa64eb24531a8669a6e25546", null ],
      [ "CYHAL_RSC_CLKPATH", "group__group__hal__impl__hw__types.html#gga63b023ea7b5e73db59ddc0423c77975ba59ccc8aae425c4249a6d44a211b9e13a", null ],
      [ "CYHAL_RSC_CLOCK", "group__group__hal__impl__hw__types.html#gga63b023ea7b5e73db59ddc0423c77975ba87c497b200dfbc0c5daf9617a89f4aa7", null ],
      [ "CYHAL_RSC_CRYPTO", "group__group__hal__impl__hw__types.html#gga63b023ea7b5e73db59ddc0423c77975ba25fa2cb684b519d6826067ce6d5d1afe", null ],
      [ "CYHAL_RSC_DAC", "group__group__hal__impl__hw__types.html#gga63b023ea7b5e73db59ddc0423c77975badad76bbe79d1dd504f44296427c38fe2", null ],
      [ "CYHAL_RSC_DMA", "group__group__hal__impl__hw__types.html#gga63b023ea7b5e73db59ddc0423c77975badd087e136a6661d42919ab8c145a395f", null ],
      [ "CYHAL_RSC_DW", "group__group__hal__impl__hw__types.html#gga63b023ea7b5e73db59ddc0423c77975ba1f6f00a8d9b758e0ea4a1ad8da3f5dd0", null ],
      [ "CYHAL_RSC_ETH", "group__group__hal__impl__hw__types.html#gga63b023ea7b5e73db59ddc0423c77975ba8c2913af9005b4c7df4bf78466e5768d", null ],
      [ "CYHAL_RSC_GPIO", "group__group__hal__impl__hw__types.html#gga63b023ea7b5e73db59ddc0423c77975ba5f4259788e0fc887772496df602d7549", null ],
      [ "CYHAL_RSC_I2S", "group__group__hal__impl__hw__types.html#gga63b023ea7b5e73db59ddc0423c77975ba6b93380724a9f1c695cf1f7a2e993a90", null ],
      [ "CYHAL_RSC_I3C", "group__group__hal__impl__hw__types.html#gga63b023ea7b5e73db59ddc0423c77975ba2a7f33149ef80053123f7241d82f54ae", null ],
      [ "CYHAL_RSC_KEYSCAN", "group__group__hal__impl__hw__types.html#gga63b023ea7b5e73db59ddc0423c77975ba80269a16f097ec14da8581cffee6fc6c", null ],
      [ "CYHAL_RSC_LCD", "group__group__hal__impl__hw__types.html#gga63b023ea7b5e73db59ddc0423c77975ba66e93a0a9834e5b16a3156d87ad993e4", null ],
      [ "CYHAL_RSC_LIN", "group__group__hal__impl__hw__types.html#gga63b023ea7b5e73db59ddc0423c77975ba2f8d1b23b0adbf9da955873088a109b3", null ],
      [ "CYHAL_RSC_LPCOMP", "group__group__hal__impl__hw__types.html#gga63b023ea7b5e73db59ddc0423c77975ba66b3400d94288b89d49def6194537bbe", null ],
      [ "CYHAL_RSC_LPTIMER", "group__group__hal__impl__hw__types.html#gga63b023ea7b5e73db59ddc0423c77975ba6408a108cf029e1e7b69c98ce86320e7", null ],
      [ "CYHAL_RSC_OPAMP", "group__group__hal__impl__hw__types.html#gga63b023ea7b5e73db59ddc0423c77975ba279192cbd81c5e71e5f4c3939d2e96a8", null ],
      [ "CYHAL_RSC_PDM", "group__group__hal__impl__hw__types.html#gga63b023ea7b5e73db59ddc0423c77975ba9123cdde61ea752aa7c362b3f9ca2814", null ],
      [ "CYHAL_RSC_SMIF", "group__group__hal__impl__hw__types.html#gga63b023ea7b5e73db59ddc0423c77975ba0b3f19bcd7698ff1293d1bcbccb31b77", null ],
      [ "CYHAL_RSC_RTC", "group__group__hal__impl__hw__types.html#gga63b023ea7b5e73db59ddc0423c77975ba65ea21d45fd38e900113b40eb3849236", null ],
      [ "CYHAL_RSC_SCB", "group__group__hal__impl__hw__types.html#gga63b023ea7b5e73db59ddc0423c77975bac1349fcb893be326bcd28ed254bd7a80", null ],
      [ "CYHAL_RSC_SDHC", "group__group__hal__impl__hw__types.html#gga63b023ea7b5e73db59ddc0423c77975baf35ab7112b4bcd054bdb0874a441155a", null ],
      [ "CYHAL_RSC_SDIODEV", "group__group__hal__impl__hw__types.html#gga63b023ea7b5e73db59ddc0423c77975bacf1bf2d42c5a1e89c1e4acca4988c752", null ],
      [ "CYHAL_RSC_TCPWM", "group__group__hal__impl__hw__types.html#gga63b023ea7b5e73db59ddc0423c77975baa445456a2983f23d4be55613f2d09eb6", null ],
      [ "CYHAL_RSC_TDM", "group__group__hal__impl__hw__types.html#gga63b023ea7b5e73db59ddc0423c77975ba4f5bf99fff8a2e7d669855fd7a86a4ed", null ],
      [ "CYHAL_RSC_UDB", "group__group__hal__impl__hw__types.html#gga63b023ea7b5e73db59ddc0423c77975ba446a3390d41bd50e12d0b8f0c1715a53", null ],
      [ "CYHAL_RSC_USB", "group__group__hal__impl__hw__types.html#gga63b023ea7b5e73db59ddc0423c77975bae7778bb22af66e6dfb5c620d6c3c9108", null ],
      [ "CYHAL_RSC_INVALID", "group__group__hal__impl__hw__types.html#gga63b023ea7b5e73db59ddc0423c77975baf4c05e33bb994cc6a1d94bd301dcc988", null ]
    ] ],
    [ "cyhal_clock_block_t", "group__group__hal__impl__hw__types.html#ga1968e793be1599de10dec9e2d48f66d6", null ],
    [ "_cyhal_sdxx_data_transfer_status_t", "group__group__hal__impl__hw__types.html#ga4c8ca0fbe680910a4a1059b24af6be33", [
      [ "_CYHAL_SDXX_NOT_RUNNING", "group__group__hal__impl__hw__types.html#gga4c8ca0fbe680910a4a1059b24af6be33a368ff869cdb24a321d3da688a1d26500", null ],
      [ "_CYHAL_SDXX_WAIT_CMD_COMPLETE", "group__group__hal__impl__hw__types.html#gga4c8ca0fbe680910a4a1059b24af6be33ae8959540814b72dc9da8734e16af2e27", null ],
      [ "_CYHAL_SDXX_WAIT_XFER_COMPLETE", "group__group__hal__impl__hw__types.html#gga4c8ca0fbe680910a4a1059b24af6be33ae0ce7792911e7d6ba534c57a58ee7f95", null ],
      [ "_CYHAL_SDXX_WAIT_BOTH", "group__group__hal__impl__hw__types.html#gga4c8ca0fbe680910a4a1059b24af6be33afac7177299deca53e008ef0a984f5a1e", null ]
    ] ]
];