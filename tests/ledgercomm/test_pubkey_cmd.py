def test_get_public_key(cmd):
    (pub_key_x, pub_key_y) = cmd.get_public_key(
        bip32_path="m/2645'/1195502025'/1148870696'/0'/0'/0",
        display=True
    )  # type: bytes
