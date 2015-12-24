// -*- C++ -*-
#ifndef _SitRepPanel_h_
#define _SitRepPanel_h_

#include <GG/GGFwd.h>
#include <GG/ListBox.h>
#include "CUIWnd.h"

class SitRepEntry;


class SitRepPanel : public CUIWnd {
public:
    /** \name Structors */ //@{
    SitRepPanel(const std::string& config_name = ""); ///< basic ctor
    //@}

    /** \name Accessors */ //@{
    std::set<std::string>   HiddenSitRepTemplates() const { return m_hidden_sitrep_templates; }
    int                     NumVisibleSitrepsThisTurn() const;
    //@}

    /** \name Mutators */ //@{
    virtual void    KeyPress (GG::Key key, boost::uint32_t key_code_point, GG::Flags<GG::ModKey> mod_keys);
    virtual void    SizeMove(const GG::Pt& ul, const GG::Pt& lr);

    void            Update(); ///< loads all the relevant SitReps into the window

    void            ShowSitRepsForTurn(int turn);
    void            SetHiddenSitRepTemplates(const std::set<std::string>& templates);
    //@}

    mutable boost::signals2::signal<void ()> ClosingSignal;

private:
    virtual void    CloseClicked();
    void            PrevClicked();
    void            NextClicked();
    void            LastClicked();
    void            FilterClicked();
    void            DismissSitRep(GG::ListBox::iterator it, const GG::Pt& pt, const GG::Flags<GG::ModKey>& mod);
    void            DismissalMenu(GG::ListBox::iterator it, const GG::Pt& pt, const GG::Flags<GG::ModKey>& mod);
    void            DoLayout();

    int             GetNextNonEmptySitrepsTurn(const std::map<int, std::list<SitRepEntry> >& turns,
                                               int turn, bool forward) const;   ///< Return next turn with sitreps

    GG::ListBox*            m_sitreps_lb;
    GG::Button*             m_prev_turn_button;
    GG::Button*             m_next_turn_button;
    GG::Button*             m_last_turn_button;
    GG::Button*             m_filter_button;

    int                     m_showing_turn;
    std::set<std::string>   m_hidden_sitrep_templates;
};

#endif // _SitRepPanel_h_
