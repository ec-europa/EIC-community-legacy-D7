Feature: Group access
  Test group access

  @api
  Scenario: Check restricted access by domain
    Given I am logged in as the "mariecurie"
     Then I should not see "Log in"
