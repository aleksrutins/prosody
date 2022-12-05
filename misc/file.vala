namespace Prosody.Util {
    private Bytes read_file(File file) throws GLib.Error {
        var istream = file.read();
        istream.seek(0, SeekType.END);
        var buffer = new uint8[istream.tell()];
        istream.seek(0, SeekType.SET);
        size_t len;
        istream.read_all(buffer, out len);
        return new Bytes(buffer);
    }
}