/*
   +----------------------------------------------------------------------+
   | HipHop for PHP                                                       |
   +----------------------------------------------------------------------+
   | Copyright (c) 2010-2015 Facebook, Inc. (http://www.facebook.com)     |
   +----------------------------------------------------------------------+
   | This source file is subject to version 3.01 of the PHP license,      |
   | that is bundled with this package in the file LICENSE, and is        |
   | available through the world-wide-web at the following url:           |
   | http://www.php.net/license/3_01.txt                                  |
   | If you did not receive a copy of the PHP license and are unable to   |
   | obtain it through the world-wide-web, please send a note to          |
   | license@php.net so we can mail you a copy immediately.               |
   +----------------------------------------------------------------------+
*/

#ifndef incl_HPHP_EXP_STATEMENT_H_
#define incl_HPHP_EXP_STATEMENT_H_

#include "hphp/compiler/statement/statement.h"

namespace HPHP {
///////////////////////////////////////////////////////////////////////////////

DECLARE_BOOST_TYPES(ExpStatement);

class ExpStatement : public Statement, public IParseHandler {
public:
  ExpStatement(STATEMENT_CONSTRUCTOR_PARAMETERS, ExpressionPtr exp);

  DECLARE_STATEMENT_VIRTUAL_FUNCTIONS;

  StatementPtr preOptimize(AnalysisResultConstPtr ar) override;
  int getLocalEffects() const override { return NoEffect;}

  ExpressionPtr getExpression() { return m_exp;}

  void onParse(AnalysisResultConstPtr ar, FileScopePtr scope) override;

  bool kidUnused(int i) const override { return i == 0; }
private:
  ExpressionPtr m_exp;
  bool shouldEmitStatement() const;
};

///////////////////////////////////////////////////////////////////////////////
}
#endif // incl_HPHP_EXP_STATEMENT_H_
