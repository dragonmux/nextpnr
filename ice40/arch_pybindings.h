/*
 *  nextpnr -- Next Generation Place and Route
 *
 *  Copyright (C) 2018  Clifford Wolf <clifford@symbioticeda.com>
 *  Copyright (C) 2018  David Shah <david@symbioticeda.com>
 *
 *  Permission to use, copy, modify, and/or distribute this software for any
 *  purpose with or without fee is hereby granted, provided that the above
 *  copyright notice and this permission notice appear in all copies.
 *
 *  THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 *  WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 *  MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 *  ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 *  WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 *  ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 *  OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 *
 */
#ifndef ARCH_PYBINDINGS_H
#define ARCH_PYBINDINGS_H
#ifndef NO_PYTHON

#include "nextpnr.h"
#include "pybindings.h"

NEXTPNR_NAMESPACE_BEGIN

namespace PythonConversion {

template <> struct string_converter<BelId>
{
    BelId from_str(Context *ctx, std::string name) { return ctx->getBelByName(ctx->id(name)); }

    std::string to_str(Context *ctx, BelId id)
    {
        if (id == BelId())
            throw bad_wrap();
        return ctx->getBelName(id).str(ctx);
    }
};

template <> struct string_converter<WireId>
{
    WireId from_str(Context *ctx, std::string name) { return ctx->getWireByName(ctx->id(name)); }

    std::string to_str(Context *ctx, WireId id)
    {
        if (id == WireId())
            throw bad_wrap();
        return ctx->getWireName(id).str(ctx);
    }
};

template <> struct string_converter<const WireId>
{
    WireId from_str(Context *ctx, std::string name) { return ctx->getWireByName(ctx->id(name)); }

    std::string to_str(Context *ctx, WireId id)
    {
        if (id == WireId())
            throw bad_wrap();
        return ctx->getWireName(id).str(ctx);
    }
};

template <> struct string_converter<PipId>
{
    PipId from_str(Context *ctx, std::string name) { return ctx->getPipByName(ctx->id(name)); }

    std::string to_str(Context *ctx, PipId id)
    {
        if (id == PipId())
            throw bad_wrap();
        return ctx->getPipName(id).str(ctx);
    }
};

template <> struct string_converter<BelBucketId>
{
    BelBucketId from_str(Context *ctx, std::string name) { return ctx->getBelBucketByName(ctx->id(name)); }

    std::string to_str(Context *ctx, BelBucketId id)
    {
        if (id == BelBucketId())
            throw bad_wrap();
        return ctx->getBelBucketName(id).str(ctx);
    }
};

template <> struct string_converter<BelPin>
{
    BelPin from_str(Context *ctx, std::string name)
    {
        NPNR_ASSERT_FALSE("string_converter<BelPin>::from_str not implemented");
    }

    std::string to_str(Context *ctx, BelPin pin)
    {
        if (pin.bel == BelId())
            throw bad_wrap();
        return ctx->getBelName(pin.bel).str(ctx) + "/" + pin.pin.str(ctx);
    }
};

} // namespace PythonConversion

NEXTPNR_NAMESPACE_END
#endif
#endif
