/*
 * Copyright (c) 2015 Cryptonomex, Inc., and contributors.
 *
 * The MIT License
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#include <evolution/chain/global_property_object.hpp>
#include <evolution/chain/protocol/vote.hpp>
#include <fc/variant.hpp>

namespace evolution { namespace chain {

vote_id_type get_next_vote_id( global_property_object& gpo, vote_id_type::vote_type type )
{
   return vote_id_type( type, gpo.next_available_vote_id++ );
}

} } // evolution::chain

namespace fc
{

void to_variant(const evolution::chain::vote_id_type& var, variant& vo)
{
   vo = string(var);
}

void from_variant(const variant& var, evolution::chain::vote_id_type& vo)
{
   vo = evolution::chain::vote_id_type(var.as_string());
}

} // fc
