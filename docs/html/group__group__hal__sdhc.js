var group__group__hal__sdhc =
[
    [ "SDHC HAL Results", "group__group__hal__results__sdhc.html", "group__group__hal__results__sdhc" ],
    [ "cyhal_sdhc_config_t", "group__group__hal__sdhc.html#structcyhal__sdhc__config__t", [
      [ "enableLedControl", "group__group__hal__sdhc.html#a9a0d3720e7b0898f436fd51dc3f65ab2", null ],
      [ "lowVoltageSignaling", "group__group__hal__sdhc.html#a34288a41b330982ab1a584953922d8f3", null ],
      [ "isEmmc", "group__group__hal__sdhc.html#a91ccb95e1df1b03b3786644e953c005d", null ],
      [ "busWidth", "group__group__hal__sdhc.html#aab3e73af9b4102da9a5c53e535bd2a83", null ]
    ] ],
    [ "cyhal_sdhc_data_config_t", "group__group__hal__sdhc.html#structcyhal__sdhc__data__config__t", [
      [ "data_ptr", "group__group__hal__sdhc.html#a198253d7fd6bdb4bf70c642d77c05bf1", null ],
      [ "block_size", "group__group__hal__sdhc.html#a0e76ea9197d0a8dfe013fdf7a5bf84f5", null ],
      [ "number_of_blocks", "group__group__hal__sdhc.html#ab97ff73c5cc53db36aa92ffb84ba35de", null ],
      [ "auto_command", "group__group__hal__sdhc.html#a2822a66fa6410eceba81604567e11c82", null ],
      [ "is_read", "group__group__hal__sdhc.html#a3e7011f4e15e4f21b7688112593860b7", null ]
    ] ],
    [ "cyhal_sdhc_cmd_config_t", "group__group__hal__sdhc.html#structcyhal__sdhc__cmd__config__t", [
      [ "command_index", "group__group__hal__sdhc.html#a9ee2bda5fbcf52d015c007c201d77600", null ],
      [ "command_argument", "group__group__hal__sdhc.html#a6ec506e9315f9624d8040cf7b0d41e51", null ],
      [ "enable_crc_check", "group__group__hal__sdhc.html#a53d4b0e0ce161544068ca72c7a64ac64", null ],
      [ "response_type", "group__group__hal__sdhc.html#ad9cb1a8070e3a07af83f8a173926d556", null ],
      [ "enable_idx_check", "group__group__hal__sdhc.html#a6b0757bad40941cb717e9152fbf35084", null ],
      [ "command_type", "group__group__hal__sdhc.html#abaab066571dc422286bad033eed84c01", null ],
      [ "data_config", "group__group__hal__sdhc.html#a54717ed5ce1dcf41110f0e3964782c6d", null ]
    ] ],
    [ "cyhal_sdhc_event_callback_t", "group__group__hal__sdhc.html#gaded71f4751306e4983c1e8315c569fa1", null ],
    [ "cyhal_sdhc_card_type_t", "group__group__hal__sdhc.html#ga612f43553069268d48d7ce0bee45722a", [
      [ "CYHAL_SDHC_SD", "group__group__hal__sdhc.html#gga612f43553069268d48d7ce0bee45722aa38bcb59920941b83f0c06332df4cfc56", null ],
      [ "CYHAL_SDHC_SDIO", "group__group__hal__sdhc.html#gga612f43553069268d48d7ce0bee45722aac83d0855095c3088049b98df879f5b81", null ],
      [ "CYHAL_SDHC_EMMC", "group__group__hal__sdhc.html#gga612f43553069268d48d7ce0bee45722aa8c0d3085eecb94c70be970fd616ad478", null ],
      [ "CYHAL_SDHC_COMBO", "group__group__hal__sdhc.html#gga612f43553069268d48d7ce0bee45722aa0634c94b291436bcd2ff7810df539610", null ],
      [ "CYHAL_SDHC_UNUSABLE", "group__group__hal__sdhc.html#gga612f43553069268d48d7ce0bee45722aa824d9d7d02b24e15f4310f1697477a9f", null ],
      [ "CYHAL_SDHC_NOT_EMMC", "group__group__hal__sdhc.html#gga612f43553069268d48d7ce0bee45722aa2e07f8e30e45059fee59fcf4e341a925", null ]
    ] ],
    [ "cyhal_sdhc_event_t", "group__group__hal__sdhc.html#gab58a2ffca59383a72cf8bc49d74cf17b", [
      [ "CYHAL_SDHC_CMD_COMPLETE", "group__group__hal__sdhc.html#ggab58a2ffca59383a72cf8bc49d74cf17ba11e93e28cdb3730b5f8c6bb5f29cb7d5", null ],
      [ "CYHAL_SDHC_XFER_COMPLETE", "group__group__hal__sdhc.html#ggab58a2ffca59383a72cf8bc49d74cf17bad08d507a635f8269ba7649643339f213", null ],
      [ "CYHAL_SDHC_BGAP_EVENT", "group__group__hal__sdhc.html#ggab58a2ffca59383a72cf8bc49d74cf17ba7cc7318fbda0daa6154e29752dead031", null ],
      [ "CYHAL_SDHC_DMA_INTERRUPT", "group__group__hal__sdhc.html#ggab58a2ffca59383a72cf8bc49d74cf17ba80af4d0d45768f30bb1e7e20580eccb5", null ],
      [ "CYHAL_SDHC_BUF_WR_READY", "group__group__hal__sdhc.html#ggab58a2ffca59383a72cf8bc49d74cf17ba41feae89fc60f05dc290968dea4a382b", null ],
      [ "CYHAL_SDHC_BUF_RD_READY", "group__group__hal__sdhc.html#ggab58a2ffca59383a72cf8bc49d74cf17ba3844ed703bfd516cd920d251a2d60b89", null ],
      [ "CYHAL_SDHC_CARD_INSERTION", "group__group__hal__sdhc.html#ggab58a2ffca59383a72cf8bc49d74cf17ba2cd1dd430b29e174da66c8d08cbaca17", null ],
      [ "CYHAL_SDHC_CARD_REMOVAL", "group__group__hal__sdhc.html#ggab58a2ffca59383a72cf8bc49d74cf17ba43775fcc705ff58f61b111825bdb34f2", null ],
      [ "CYHAL_SDHC_RE_TUNE_EVENT", "group__group__hal__sdhc.html#ggab58a2ffca59383a72cf8bc49d74cf17bac79ac0f3bae5a083079c478099b6f6fc", null ],
      [ "CYHAL_SDHC_FX_EVENT", "group__group__hal__sdhc.html#ggab58a2ffca59383a72cf8bc49d74cf17bac5d8eae9a3ca751227264f692a4f9ebd", null ],
      [ "CYHAL_SDHC_CQE_EVENT", "group__group__hal__sdhc.html#ggab58a2ffca59383a72cf8bc49d74cf17bab1f59c81773e6e2083623bee85dd9c9b", null ],
      [ "CYHAL_SDHC_ERR_INTERRUPT", "group__group__hal__sdhc.html#ggab58a2ffca59383a72cf8bc49d74cf17bae5a8f7697409d7c683405808581a9a57", null ],
      [ "CYHAL_SDHC_ALL_INTERRUPTS", "group__group__hal__sdhc.html#ggab58a2ffca59383a72cf8bc49d74cf17ba3be10ae218d0d48ef63f98a9238fac46", null ]
    ] ],
    [ "cyhal_sdhc_io_voltage_t", "group__group__hal__sdhc.html#ga11968d8b79af97a6a319fa709d84861e", [
      [ "CYHAL_SDHC_IO_VOLTAGE_3_3V", "group__group__hal__sdhc.html#gga11968d8b79af97a6a319fa709d84861ea73c0e6ae5ad1181266b9228447065006", null ],
      [ "CYHAL_SDHC_IO_VOLTAGE_1_8V", "group__group__hal__sdhc.html#gga11968d8b79af97a6a319fa709d84861eac68fd890d8ac8bcbf19bf07dd59a50ab", null ]
    ] ],
    [ "cyhal_sdhc_io_volt_action_type_t", "group__group__hal__sdhc.html#ga5e3877ab007a39419bdefc0abae2713d", [
      [ "CYHAL_SDHC_IO_VOLT_ACTION_NEGOTIATE", "group__group__hal__sdhc.html#gga5e3877ab007a39419bdefc0abae2713dad0ce65c933019daf09508992c47fd22e", null ],
      [ "CYHAL_SDHC_IO_VOLT_ACTION_SWITCH_SEQ_ONLY", "group__group__hal__sdhc.html#gga5e3877ab007a39419bdefc0abae2713dadc0de97a76aca9884a9a13e8efeb0477", null ],
      [ "CYHAL_SDHC_IO_VOLT_ACTION_NONE", "group__group__hal__sdhc.html#gga5e3877ab007a39419bdefc0abae2713da3463e1d05c9ee096b7a34485102a216c", null ]
    ] ],
    [ "cyhal_sdhc_cmd_response_type_t", "group__group__hal__sdhc.html#gace71512915eb3049e3e7552f98db94c6", [
      [ "CYHAL_SDHC_RESPONSE_NONE", "group__group__hal__sdhc.html#ggace71512915eb3049e3e7552f98db94c6a05d0960fc0a1479992bd79a2b64d3dca", null ],
      [ "CYHAL_SDHC_RESPONSE_LEN_136", "group__group__hal__sdhc.html#ggace71512915eb3049e3e7552f98db94c6ae3f5e48c73db2df1f853696a7706823d", null ],
      [ "CYHAL_SDHC_RESPONSE_LEN_48", "group__group__hal__sdhc.html#ggace71512915eb3049e3e7552f98db94c6aa6ebcd52cc80521f8f48ddbccf31deaf", null ],
      [ "CYHAL_SDHC_RESPONSE_LEN_48B", "group__group__hal__sdhc.html#ggace71512915eb3049e3e7552f98db94c6a8d4401145983ee476ae2eff3de75a1a3", null ]
    ] ],
    [ "cyhal_sdhc_auto_cmd_t", "group__group__hal__sdhc.html#ga13894ce8370fdb77b0c671f68d8582b5", [
      [ "CYHAL_SDHC_AUTO_CMD_NONE", "group__group__hal__sdhc.html#gga13894ce8370fdb77b0c671f68d8582b5ad7e842622775bc21006065b8ea632608", null ],
      [ "CYHAL_SDHC_AUTO_CMD_12", "group__group__hal__sdhc.html#gga13894ce8370fdb77b0c671f68d8582b5af7b957a3b349ad65ceb72b1c6f680fde", null ],
      [ "CYHAL_SDHC_AUTO_CMD_23", "group__group__hal__sdhc.html#gga13894ce8370fdb77b0c671f68d8582b5abc8844e11d9625d183155d4acb1664ca", null ],
      [ "CYHAL_SDHC_AUTO_CMD_AUTO", "group__group__hal__sdhc.html#gga13894ce8370fdb77b0c671f68d8582b5ac13a07d3c99d967c0e6ed1380109c940", null ]
    ] ],
    [ "cyhal_sdhc_cmd_type_t", "group__group__hal__sdhc.html#ga618579f234c8defbcfdb926567fdac53", [
      [ "CYHAL_SDHC_CMD_NORMAL", "group__group__hal__sdhc.html#gga618579f234c8defbcfdb926567fdac53a36615e661801fe533af2b9cf50e75a24", null ],
      [ "CYHAL_SDHC_CMD_SUSPEND", "group__group__hal__sdhc.html#gga618579f234c8defbcfdb926567fdac53a9edcd2d96fcff621a64ff35fa94e4f5c", null ],
      [ "CYHAL_SDHC_CMD_RESUME", "group__group__hal__sdhc.html#gga618579f234c8defbcfdb926567fdac53aac4de4e8b13f837037b583d9c48d4667", null ],
      [ "CYHAL_SDHC_CMD_ABORT", "group__group__hal__sdhc.html#gga618579f234c8defbcfdb926567fdac53a5fccf029ce7fab7358f48a68ed282a03", null ]
    ] ],
    [ "cyhal_sdhc_error_type_t", "group__group__hal__sdhc.html#ga3068735fe5a653edd9685a426680718f", [
      [ "CYHAL_SDHC_NO_ERR", "group__group__hal__sdhc.html#gga3068735fe5a653edd9685a426680718faa96477f37a1ee53d18582a46b76d1f7c", null ],
      [ "CYHAL_SDHC_CMD_TOUT_ERR", "group__group__hal__sdhc.html#gga3068735fe5a653edd9685a426680718fa271c70503e2bf0873a64176c6ec8c3b1", null ],
      [ "CYHAL_SDHC_CMD_CRC_ERR", "group__group__hal__sdhc.html#gga3068735fe5a653edd9685a426680718fa237628754613a4eeb3453cceeb1a0273", null ],
      [ "CYHAL_SDHC_CMD_END_BIT_ERR", "group__group__hal__sdhc.html#gga3068735fe5a653edd9685a426680718faf2e99e3da3bd9ba10657f1779f62fc05", null ],
      [ "CYHAL_SDHC_CMD_IDX_ERR", "group__group__hal__sdhc.html#gga3068735fe5a653edd9685a426680718fa787711273ba228a9d23aff252306a9c9", null ],
      [ "CYHAL_SDHC_DATA_TOUT_ERR", "group__group__hal__sdhc.html#gga3068735fe5a653edd9685a426680718fa796b6781401eb24261f767f4d6884c52", null ],
      [ "CYHAL_SDHC_DATA_CRC_ERR", "group__group__hal__sdhc.html#gga3068735fe5a653edd9685a426680718fac8965b429acf3aaf03b49c8e2fed3517", null ],
      [ "CYHAL_SDHC_DATA_END_BIT_ERR", "group__group__hal__sdhc.html#gga3068735fe5a653edd9685a426680718fa7516f48c153ea4ed61cee8ca39406cfc", null ],
      [ "CYHAL_SDHC_CUR_LMT_ERR", "group__group__hal__sdhc.html#gga3068735fe5a653edd9685a426680718fad53a96ca3a4e021e167086f02530ed2b", null ],
      [ "CYHAL_SDHC_AUTO_CMD_ERR", "group__group__hal__sdhc.html#gga3068735fe5a653edd9685a426680718fa71327bee1ee79a2210c92c130335734c", null ],
      [ "CYHAL_SDHC_ADMA_ERR", "group__group__hal__sdhc.html#gga3068735fe5a653edd9685a426680718fa7b671e9257a366ae19f0837daf892569", null ],
      [ "CYHAL_SDHC_TUNNING_ERR", "group__group__hal__sdhc.html#gga3068735fe5a653edd9685a426680718fa21bfcd58db3c064562a61ddb40decf19", null ],
      [ "CYHAL_SDHC_RESP_ERR", "group__group__hal__sdhc.html#gga3068735fe5a653edd9685a426680718fabc9cfeaf9cbbdbd0076cc55c91dacac0", null ],
      [ "CYHAL_SDHC_BOOT_ACK_ERR", "group__group__hal__sdhc.html#gga3068735fe5a653edd9685a426680718faa685467b4ff2fdcc9945db71a2d70a48", null ]
    ] ],
    [ "cyhal_sdhc_init_hw", "group__group__hal__sdhc.html#ga182c2577ba3f8b9ac1d1c8c2279821c6", null ],
    [ "cyhal_sdhc_init_card", "group__group__hal__sdhc.html#ga1c042de1a92c5f2ecbdfa5bc989af209", null ],
    [ "cyhal_sdhc_init", "group__group__hal__sdhc.html#gaf86d1e6bf7e17df1bece81bc1a5ebdd5", null ],
    [ "cyhal_sdhc_free", "group__group__hal__sdhc.html#ga3fb2c77d8662f53a21996298cb4581b1", null ],
    [ "cyhal_sdhc_read", "group__group__hal__sdhc.html#ga4714e8b2507eefd5e6df9105f2944a1e", null ],
    [ "cyhal_sdhc_write", "group__group__hal__sdhc.html#ga5a7d14246fee3ef70ec2d9ce4abf066a", null ],
    [ "cyhal_sdhc_erase", "group__group__hal__sdhc.html#gac3b257d6386f9699d70ca378bb02c7cb", null ],
    [ "cyhal_sdhc_read_async", "group__group__hal__sdhc.html#gad020348569b21c43181c0c46e68ce05c", null ],
    [ "cyhal_sdhc_write_async", "group__group__hal__sdhc.html#gac46d4b112279c8a2eabe61769faab39d", null ],
    [ "cyhal_sdhc_is_busy", "group__group__hal__sdhc.html#gad28a8b2178173ce3ee981453ed3ce12c", null ],
    [ "cyhal_sdhc_abort_async", "group__group__hal__sdhc.html#ga1b3044289cec6662efea36bd4054bf7b", null ],
    [ "cyhal_sdhc_register_callback", "group__group__hal__sdhc.html#ga1fe53d842050280b8827e9a41545f461", null ],
    [ "cyhal_sdhc_enable_event", "group__group__hal__sdhc.html#ga3a0865321bd9284606655f9fb9402339", null ],
    [ "cyhal_sdhc_is_card_inserted", "group__group__hal__sdhc.html#ga616760d8368e5253716bf8bb5aaec2d9", null ],
    [ "cyhal_sdhc_is_card_mech_write_protected", "group__group__hal__sdhc.html#ga93db8de844c759af35280a968551215c", null ],
    [ "cyhal_sdhc_get_block_count", "group__group__hal__sdhc.html#ga3f055dca9939fa3d20e4846f8348a856", null ],
    [ "cyhal_sdhc_set_frequency", "group__group__hal__sdhc.html#ga61cd4c3f5f243e1dfc44ad91f2056d60", null ],
    [ "cyhal_sdhc_get_frequency", "group__group__hal__sdhc.html#ga38e75dc7fda0b2eaef8a064566cba6ca", null ],
    [ "cyhal_sdhc_set_data_read_timeout", "group__group__hal__sdhc.html#ga016c5b6b472837548527230c9a98edff", null ],
    [ "cyhal_sdhc_config_data_transfer", "group__group__hal__sdhc.html#ga60d64dc06c541217ebe7f36dc6498ace", null ],
    [ "cyhal_sdhc_send_cmd", "group__group__hal__sdhc.html#gafb5534f9654bbd459481936c5abe40ad", null ],
    [ "cyhal_sdhc_get_response", "group__group__hal__sdhc.html#gad9bff4cfd487a33cd6dd62d49e7d2969", null ],
    [ "cyhal_sdhc_wait_transfer_complete", "group__group__hal__sdhc.html#ga670468d4cd69e7b65225faa35996575c", null ],
    [ "cyhal_sdhc_set_io_voltage", "group__group__hal__sdhc.html#gae6612fc9362124a783f8b47add69dde4", null ],
    [ "cyhal_sdhc_get_io_voltage", "group__group__hal__sdhc.html#gae07049e08e19fe729d8a5705ea3765c0", null ],
    [ "cyhal_sdhc_set_bus_width", "group__group__hal__sdhc.html#ga53fbe8b3e43ff23270c6fe09c5eceea7", null ],
    [ "cyhal_sdhc_get_bus_width", "group__group__hal__sdhc.html#gaf8864c53c6bcb103a95040874af92102", null ],
    [ "cyhal_sdhc_get_last_command_errors", "group__group__hal__sdhc.html#ga833da009de635170a856779d34f6a1e5", null ],
    [ "cyhal_sdhc_clear_errors", "group__group__hal__sdhc.html#gaaee5b8314adf44cb3f10cdac88537e98", null ],
    [ "cyhal_sdhc_software_reset", "group__group__hal__sdhc.html#ga88369bc8abc3567def254b6ca65291be", null ],
    [ "cyhal_sdhc_enable_card_power", "group__group__hal__sdhc.html#gaf3fd9221a57b5667adc97b31ad71fdd5", null ]
];